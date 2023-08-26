/// `Allergies` holds a collection of allergens.
pub struct Allergies
{ allergens: Vec<Allergen> }

/// `Allergen` enumerates possible allergens a person can be allergic to.
#[derive(Clone, Copy, Debug, PartialEq, Eq)]
pub enum Allergen
{
	Eggs,
	Peanuts,
	Shellfish,
	Strawberries,
	Tomatoes,
	Chocolate,
	Pollen,
	Cats
}

/// List of all possible allergens used in this implementation.
const ALLERGENS: [Allergen; 8] =
[
	Eggs,
	Peanuts,
	Shellfish,
	Strawberries,
	Tomatoes,
	Chocolate,
	Pollen,
	Cats
];

impl Allergies
{
	/// Creates a new `Allergies` instance based on a score.
	///
	/// Each bit in the score corresponds to an allergen in `ALLERGENS`.
	pub fn new(score: u32) -> Self
	{
		let mut allergens = Vec::new();

		// Iterate over the first 8 bits of `score` to identify allergens.
		for i in 0..=7
		{
			// If the bit at position `i` is set, add the corresponding allergen.
			if (score >> i) & 1 == 1
			{ allergens.push(ALLERGENS[i]); }
		}

		Allergies { allergens }
	}

	/// Checks if the person is allergic to the given `allergen`.
	pub fn is_allergic_to(&self, allergen: &Allergen) -> bool
	{ self.allergies().contains(allergen) }

	/// Returns a clone of the allergens vector.
	pub fn allergies(&self) -> Vec<Allergen>
	{ self.allergens.clone() }
}
