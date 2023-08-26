use std::cmp::Ordering;

/// Enum representing the possible relationships between two lists.
#[derive(Debug, PartialEq, Eq)]
pub enum Comparison
{
	Equal,
	Sublist,
	Superlist,
	Unequal
}

/// Compares two lists to determine their relationship.
///
/// The function uses the Knuth-Morris-Pratt algorithm to check if one list is a sublist,
/// superlist, or equal to another list.
///
/// # Arguments
///
/// * `_first_list` - A slice representing the first list.
/// * `_second_list` - A slice representing the second list.
///
/// # Returns
///
/// A `Comparison` enum representing the relationship between the two lists.
pub fn sublist<T: PartialEq>(_first_list: &[T], _second_list: &[T])
-> Comparison
{
	let m = _first_list.len();
	let n = _second_list.len();

	// Compare the lengths of the two lists
	match m.cmp(&n)
	{
		// Lists are equal if lengths are equal and elements are the same
		Ordering::Equal if (_first_list == _second_list) => Comparison::Equal,
		// First list is a sublist if its elements appear in order in the second list
		Ordering::Less if kmp(_first_list, _second_list) => Comparison::Sublist,
		// First list is a superlist if second list's elements appear in order in the first list
		Ordering::Greater if kmp(_second_list, _first_list) => Comparison::Superlist,
		// Lists are unequal otherwise
		_ => Comparison::Unequal,
	}
}

/// Implements the Knuth-Morris-Pratt (KMP) algorithm to search for a sublist.
///
/// # Arguments
///
/// * `pattern` - A slice representing the pattern to be searched for.
/// * `text` - A slice representing the text to search in.
///
/// # Returns
///
/// Returns `true` if the pattern is found in the text, otherwise `false`.
fn kmp<T: PartialEq>(pattern: &[T], text: &[T]) -> bool
{
	// An empty pattern is always found in any text
	if pattern.is_empty()
	{ return true; }

	let mut i = 0;	// Index for the text
	let mut j = 0;	// Index for the pattern

	let transition_table = compute_dfa(pattern);

	while i < text.len()
	{
		if pattern[j] == text[i]
		{
			i += 1;
			j += 1;

			// Pattern found in the text
			if j == pattern.len()
			{ return true; }
		}
		else if j > 0
		{ j = transition_table[j - 1]; }	// Skip to next possible match using DFA
		else
		{ i += 1; }	// No match found, move to the next character in the text
	}

	// Pattern not found in the text
	false
}

/// Computes the deterministic finite automaton (DFA) for the KMP algorithm.
///
/// # Arguments
///
/// * `pattern` - A slice representing the pattern to be searched for.
///
/// # Returns
///
/// Returns a `Vec<usize>` representing the transition table.
fn compute_dfa<T: PartialEq>(pattern: &[T]) -> Vec<usize>
{
	let pattern_length = pattern.len();

	let mut transition_table = vec![0; pattern_length];

	let mut k = 0;

	for i in 1..pattern_length
	{
		// Adjust the value of k using the transition table
		while k > 0 && pattern[k] != pattern[i]
		{ k = transition_table[k - 1]; }

		// Increment k when a match is found
		if pattern[k] == pattern[i]
		{ k += 1; }

		transition_table[i] = k;	// Store the current value of k
	}

	// Return the computed transition table
	transition_table
}
