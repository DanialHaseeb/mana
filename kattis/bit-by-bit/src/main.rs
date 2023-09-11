/// [Bit by Bit](https://open.kattis.com/problems/bitbybit)
/// **Author:** Danial Haseeb

use std::io;

fn main()
{
	let mut input = io::stdin().lines();

	let mut sequence_size: usize = input.next().unwrap().unwrap().trim().parse().unwrap();
	let mut instructions = Vec::with_capacity(sequence_size);

  while sequence_size != 0
	{
		for _ in 0..sequence_size
		{
			let instruction = input.next().unwrap().unwrap();
			instructions.push(Instruction::parse(&instruction));
		}

		let mut bits = [Bit::Unknown; 32];

		for instruction in &instructions
		{ instruction.execute(&mut bits); }

		for i in (0..32).rev()
		{
			match bits[i]
			{
				Bit::Zero => print!("0"),
				Bit::One => print!("1"),
				Bit::Unknown => print!("?"),
			}
		}

		println!();

		sequence_size = input.next().unwrap().unwrap().trim().parse().unwrap();

		instructions.clear();
	}


}

enum Instruction
{
	Clear(usize),
	Set(usize),
	Or(usize, usize),
	And(usize, usize)
}

impl Instruction
{
	fn parse(instruction: &str) -> Self
	{
		let (instruction, args) = instruction.split_once(' ').unwrap();

		match instruction
		{
			"CLEAR" => Self::parse_clear(args),
			"SET" => Self::parse_set(args),
			"OR" => Self::parse_or(args),
			"AND" => Self::parse_and(args),
			_ => unreachable!()
		}
	}

	fn parse_clear(args: &str) -> Self
	{
		let i = args.parse().unwrap();
		Self::Clear(i)
	}

	fn parse_set(args: &str) -> Self
	{
		let i = args.parse().unwrap();
		Self::Set(i)
	}

	fn parse_or(args: &str) -> Self
	{
		let (i, j) = args.split_once(' ').unwrap();
		let i = i.parse().unwrap();
		let j = j.parse().unwrap();
		Self::Or(i, j)
	}

	fn parse_and(args: &str) -> Self
	{
		let (i, j) = args.split_once(' ').unwrap();
		let i = i.parse().unwrap();
		let j = j.parse().unwrap();
		Self::And(i, j)
	}

	fn execute(&self, bits: &mut [Bit; 32])
	{
		match self
		{
			Self::Clear(i) => bits[*i] = Bit::Zero,
			Self::Set(i) => bits[*i] = Bit::One,
			Self::Or(i, j) => Self::or(bits, *i, *j),
			Self::And(i, j) => Self::and(bits, *i, *j)
		}
	}

	fn or(bits: &mut [Bit; 32], i: usize, j: usize)
	{
		match (bits[i], bits[j])
		{
			(Bit::Zero, Bit::Zero) => bits[i] = Bit::Zero,
			(Bit::One, _) | (_, Bit::One) => bits[i] = Bit::One,
			_ => bits[i] = Bit::Unknown
		}
	}

	fn and(bits: &mut [Bit; 32], i: usize, j: usize)
	{
		match (bits[i], bits[j])
		{
			(Bit::One, Bit::One) => bits[i] = Bit::One,
			(Bit::Zero, _) | (_, Bit::Zero) => bits[i] = Bit::Zero,
			_ => bits[i] = Bit::Unknown
		}
	}

}

#[derive(Clone, Copy)]
enum Bit
{
	Zero,
	One,
	Unknown
}
