use std::io;
use std::collections::{BTreeMap, HashMap};

fn main()
{
	let syntax_tree = parse();
	let (programme, source_map) = lex(&syntax_tree);

	let mut counter = 0;
	let mut variables = [0; 26];

	while counter < programme.len()
	{
		let command = &programme[counter];
		command.execute(&mut counter, &mut variables, &source_map);
		counter += 1;
	}
}


fn parse() -> BTreeMap<usize, Command>
{
	let mut syntax_tree = BTreeMap::new();

	while let Some(Ok(statement)) = io::stdin().lines().next()
  {
		let (label, command) = statement.split_once(' ').unwrap();

		let label: Label = label.parse().unwrap();
		let command = Command::parse(command);

		syntax_tree.insert(label, command);
  }

	syntax_tree
}

fn lex(syntax_tree: &BTreeMap<Label, Command>)
-> (Vec<Command>, HashMap<Label, usize>)
{
	let length = syntax_tree.len();

	let mut programme = Vec::with_capacity(length);
	let mut source_map = HashMap::with_capacity(length);

	let mut i: usize = 0;
	for (&label, command) in syntax_tree
	{
		programme.push(command.clone());
		source_map.insert(label, i);
		i += 1;
	}

	(programme, source_map)
}

fn convert(identifier: &str) -> Variable
{
	match identifier
	{
		"A" => 0,  "B" => 1,  "C" => 2,
		"D" => 3,  "E" => 4,  "F" => 5,
		"G" => 6,  "H" => 7,  "I" => 8,
		"J" => 9,  "K" => 10, "L" => 11,
		"M" => 12, "N" => 13, "O" => 14,
		"P" => 15, "Q" => 16, "R" => 17,
		"S" => 18, "T" => 19, "U" => 20,
		"V" => 21, "W" => 22, "X" => 23,
		"Y" => 24, "Z" => 25,  _  => unreachable!()
	}
}


type Variable = usize;
type Label = usize;


#[derive(Debug, Clone)]
enum Command
{
	Let(Variable, Arithmetic),
	If(Condition, Label),
	Print(Output),
	PrintLine(Output)
}

impl Command
{
	fn parse(input: &str) -> Self
	{
		let (kind, remainder) = input.split_once(' ').unwrap();

		match kind
		{
			"LET" => Self::parse_let(remainder),
			"IF" => Self::parse_if(remainder),
			"PRINT" => Self::parse_print(remainder),
			"PRINTLN" => Self::parse_print_line(remainder),
			_ => unreachable!()
		}
	}

	fn parse_let(input: &str) -> Self
	{
		let (variable, arithmetic) = input.split_once(" = ").unwrap();

		let variable = convert(variable);
		let arithmetic = Arithmetic::parse(arithmetic);

		Self::Let(variable, arithmetic)
	}

	fn parse_if(input: &str) -> Self
	{
		let (condition, label) = input.split_once(" THEN GOTO ").unwrap();

		let condition = Condition::parse(condition);
		let label: Label = label.parse().unwrap();

		Self::If(condition, label)
	}

	fn parse_print(input: &str) -> Self
	{
		let output = Output::parse(input);
		Self::Print(output)
	}

	fn parse_print_line(input: &str) -> Self
	{
		let output = Output::parse(input);
		Self::PrintLine(output)
	}

	fn execute(&self, counter: &mut usize, variables: &mut [i32; 26], source_map: &HashMap<Label, usize>)
	{
		match self
		{
			Self::Let(variable, arithmetic) =>
				assign(variable, arithmetic, variables),
			Self::If(condition, label) =>
				jump(&source_map[label], condition, counter, variables),
			Self::Print(output) =>
				print(output, variables),
			Self::PrintLine(output) =>
				println(output, variables)
		}
	}
}


#[derive(Debug, Clone)]
enum Arithmetic
{
	NoOp(Argument),
	Add(Argument, Argument),
	Subtract(Argument, Argument),
	Multiply(Argument, Argument),
	Divide(Argument, Argument)
}

impl Arithmetic
{
	fn parse(input: &str) -> Self
	{
		let mut tokens = input.split_whitespace();

		let token = tokens.next().unwrap();

		if let Some(operator) = tokens.next()
		{
			let left = token;
			let right = tokens.next().unwrap();

			let left = Argument::parse(left);
			let right = Argument::parse(right);

			match operator
			{
				"+" => Self::Add(left, right),
				"-" => Self::Subtract(left, right),
				"*" => Self::Multiply(left, right),
				"/" => Self::Divide(left, right),
				_ => unreachable!()
			}
		}
		else
		{
			let argument = Argument::parse(token);
			Self::NoOp(argument)
		}
	}

	fn evaluate(&self, variables: &[i32; 26]) -> i32
	{
		match self
		{
			Self::NoOp(argument) =>
				argument.value(variables),
			Self::Add(left, right) =>
				left.value(variables) + right.value(variables),
			Self::Subtract(left, right) =>
				left.value(variables) - right.value(variables),
			Self::Multiply(left, right) =>
				left.value(variables) * right.value(variables),
			Self::Divide(left, right) =>
				left.value(variables) / right.value(variables)
		}
	}
}


#[derive(Debug, Clone)]
enum Condition
{
	Equal(Argument, Argument),
	NotEqual(Argument, Argument),
	Greater(Argument, Argument),
	Less(Argument, Argument),
	GreaterOrEqual(Argument, Argument),
	LessOrEqual(Argument, Argument)
}

impl Condition
{
	fn parse(input: &str) -> Self
	{
		let mut tokens = input.split_whitespace();

		let left = tokens.next().unwrap();
		let operator = tokens.next().unwrap();
		let right = tokens.next().unwrap();

		let left = Argument::parse(left);
		let right = Argument::parse(right);

		match operator
		{
			"=" => Self::Equal(left, right),
			">" => Self::Greater(left, right),
			"<" => Self::Less(left, right),
			"<>" => Self::NotEqual(left, right),
			"<=" => Self::LessOrEqual(left, right),
			">=" => Self::GreaterOrEqual(left, right),
			_ => unreachable!()
		}
	}

	fn evaluate(&self, variables: &[i32; 26]) -> bool
	{
		match self
		{
			Self::Equal(left, right) =>
				left.value(variables) == right.value(variables),
			Self::NotEqual(left, right) =>
				left.value(variables) != right.value(variables),
			Self::Greater(left, right) =>
				left.value(variables) > right.value(variables),
			Self::Less(left, right) =>
				left.value(variables) < right.value(variables),
			Self::GreaterOrEqual(left, right) =>
				left.value(variables) >= right.value(variables),
			Self::LessOrEqual(left, right) =>
				left.value(variables) <= right.value(variables)
		}
	}
}


#[derive(Debug, Clone)]
enum Argument
{
	Identifier(Variable),
	Literal(i32)
}

impl Argument
{
	fn parse(input: &str) -> Self
	{
		if let Ok(identifier) = input.parse::<i32>()
		{ Self::Literal(identifier) }
		else
		{
			let identifier = convert(input);
			Self::Identifier(identifier)
		}
	}

	fn value(&self, variables: &[i32; 26]) -> i32
	{
		match self
		{
			Self::Identifier(variable) =>
				variables[*variable],
			Self::Literal(literal) =>
				*literal
		}
	}
}


#[derive(Debug, Clone)]
enum Output
{
	Identifier(Variable),
	Literal(String)
}

impl Output
{
	fn parse(input: &str) -> Self
	{
		if input.chars().next() == Some('"')
		{
			let literal = input.trim_matches('"').to_string();
			Self::Literal(literal)
		}
		else
		{
			let identifier = convert(input);
			Self::Identifier(identifier)
		}
	}
}


fn assign(variable: &Variable, arithmetic: &Arithmetic, variables: &mut [i32; 26])
{
	let value = arithmetic.evaluate(variables);
	variables[*variable] = value;
}

fn jump(label: &Label, condition: &Condition, counter: &mut usize, variables: &[i32; 26])
{
	let condition = condition.evaluate(variables);

	if condition
	{ *counter = *label - 1; }
}

fn print(output: &Output, variables: &[i32; 26])
{
	match output
	{
		Output::Identifier(variable) =>
			print!("{}", variables[*variable]),
		Output::Literal(literal) =>
			print!("{}", literal)
	}
}

fn println(output: &Output, variables: &[i32; 26])
{
	match output
	{
		Output::Identifier(variable) =>
			println!("{}", variables[*variable]),
		Output::Literal(literal) =>
			println!("{}", literal)
	}
}
