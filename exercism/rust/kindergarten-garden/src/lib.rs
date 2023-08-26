/// Returns a `Vec` of plants assigned to a given `student` based on the
/// input `_diagram` which represents rows of plants.
pub fn plants(_diagram: &str, _student: &str) -> Vec<&'static str>
{
	// Find the index corresponding to the student's first plant in the diagram.
	let index = index(_student);

	// Initialize a vector to store the plants for the student.
	let mut plants = Vec::new();

	// Split the diagram into lines representing each row of plants.
	let lines = _diagram.lines();

	// Iterate through each line of plants to identify those corresponding to the student.
	for line in lines
	{
		let mut plant_chars = line.chars();

		// Get the characters at the calculated index and next index.
		let c1 = plant_chars.nth(index).unwrap();
		let c2 = plant_chars.next().unwrap();

		// Translate the characters to plant names and add them to the student's list.
		plants.push(plant(c1));
		plants.push(plant(c2));
	}

	plants
}

/// Returns the index in the diagram where a given `student`'s first plant can be found.
fn index(student: &str) -> usize
{
	// Use a match statement to find the corresponding index for each student.
	match student
	{
		"Alice"   => 0,
		"Bob"     => 2,
		"Charlie" => 4,
		"David"   => 6,
		"Eve"     => 8,
		"Fred"    => 10,
		"Ginny"   => 12,
		"Harriet" => 14,
		"Ileana"  => 16,
		"Joseph"  => 18,
		"Kincaid" => 20,
		"Larry"   => 22,
		_ => panic!("Unknown student {}", student)
	}
}

/// Translates a character `c` representing a plant into its full name.
fn plant(c: char) -> &'static str
{
	// Use a match statement to translate each character to a plant name.
	match c
	{
		'V' => "violets",
		'R' => "radishes",
		'C' => "clover",
		'G' => "grass",
		_ => panic!("Unknown plant {}", c)
	}
}
