/// Annotates a given `minefield` by counting the number of mines adjacent
/// to each empty square. Returns a `Vec<String>` representing the annotated field.
pub fn annotate(minefield: &[&str]) -> Vec<String>
{
	// Initialize an empty vector to store the result.
	let mut result = Vec::new();

	// Loop over each row and its index in the minefield.
	for (i, row) in minefield.iter().enumerate()
	{
		let mut row_result = String::new();

		// Loop over each cell and its index in the row.
		for (j, _cell) in row.as_bytes().iter().enumerate()
		{
			// Append the count (or mine symbol) to the row_result string.
			row_result.push(count(i, j, minefield));
		}

		// Push the annotated row into the result vector.
		result.push(row_result);
	}

	result
}

/// Counts the number of mines around a given cell at `(row, col)` in `minefield`.
fn count(row: usize, col: usize, minefield: &[&str]) -> char
{
	// If the cell itself is a mine, return '*'.
	if is_mine(row, col, minefield)
	{ return '*'; }

	let mut count = 0;

	// Check each direction around the cell for mines.
	for direction in Direction::iter()
	{
		if has_mine(direction, row, col, minefield)
		{ count += 1; }
	}

	// Return the count as a char, or ' ' if count is zero.
	match count
	{
		0 => ' ',
		_ => std::char::from_digit(count, 10).unwrap()
	}
}

/// Enum to represent directions around a cell.
enum Direction
{
	Above,
	Below,
	Left,
	Right,
	AboveLeft,
	AboveRight,
	BelowLeft,
	BelowRight
}

impl Direction
{
	/// Returns an iterator over all directions.
	fn iter() -> impl Iterator<Item = Direction>
	{
		use Direction::*;
		vec![Above, Below, Left, Right, AboveLeft, AboveRight, BelowLeft, BelowRight]
			.into_iter()
	}
}

/// Checks if there is a mine in a specified `direction` from a cell at `(row, col)`.
fn has_mine(direction: Direction, row: usize, col: usize, minefield: &[&str])
-> bool
{
	use Direction::*;
	match direction
	{
		Above =>
			row > 0
			&&
			is_mine(row - 1, col, minefield),
		Below =>
			row < minefield.len() - 1
			&&
			is_mine(row + 1, col, minefield),
		Left =>
			col > 0
			&&
			is_mine(row, col - 1, minefield),
		Right =>
			col < minefield[row].len() - 1
			&&
			is_mine(row, col + 1, minefield),
		AboveLeft =>
			(row > 0) && (col > 0)
			&&
			is_mine(row - 1, col - 1, minefield),
		AboveRight =>
			(row > 0) && (col < minefield[row].len() - 1)
			&&
			is_mine(row - 1, col + 1, minefield),
		BelowLeft =>
			(row < minefield.len() - 1) && (col > 0)
			&&
			is_mine(row + 1, col - 1, minefield),
		BelowRight =>
			(row < minefield.len() - 1) && (col < minefield[row].len() - 1)
			&&
			is_mine(row + 1, col + 1, minefield)
	}
}

/// Checks if a cell at `(row, col)` is a mine.
fn is_mine(row: usize, col: usize, minefield: &[&str]) -> bool
{ minefield[row].as_bytes()[col] == b'*' }
