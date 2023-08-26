use std::collections::HashSet;

/// Function that returns a set of anagrams of a given `word` within a list of `possible_anagrams`.
pub fn anagrams_for<'a>(word: &str, possible_anagrams: &'a [&str])
-> HashSet<&'a str>
{
	/// A hash set to store found anagrams.
	let mut anagrams = HashSet::new();

	// Loop through each string in `possible_anagrams` to check if it's an anagram of `word`.
	for possible_anagram in possible_anagrams
	{
		// If the string is an anagram of `word`, insert it into the `anagrams` hash set.
		if is_anagram(word, possible_anagram)
		{ anagrams.insert(*possible_anagram); }
	}

	// Return the hash set containing all found anagrams.
	anagrams
}

/// Helper function to check if two words are anagrams of each other.
fn is_anagram(word: &str, possible_anagram: &str) -> bool
{
	// Convert both words to lowercase to make the check case-insensitive.
	let word = word.to_lowercase();
	let possible_anagram = possible_anagram.to_lowercase();

	// Early return false if lengths are not the same.
	if word.len() != possible_anagram.len()
	{ return false; }

	// Early return false if both words are identical.
	if word == possible_anagram
	{ return false; }

	// Convert both words to sorted character vectors for easy comparison.
	let mut word: Vec<char> = word.chars().collect();
	let mut possible_anagram: Vec<char> = possible_anagram.chars().collect();
	word.sort_unstable();
	possible_anagram.sort_unstable();

	// Convert character vectors back to strings.
	let word: String = word.iter().collect();
	let possible_anagram: String = possible_anagram.into_iter().collect();

	// Return true if the sorted strings are identical, meaning they are anagrams.
	word == possible_anagram
}
