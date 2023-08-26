/// A struct representing the duration in seconds.
#[derive(Debug)]
pub struct Duration
{ s: u64 }

/// Conversion from `u64` to `Duration`.
impl From<u64> for Duration
{
	fn from(s: u64) -> Self
	{ Duration{ s } }
}

/// A trait representing a planet.
pub trait Planet
{ fn years_during(d: &Duration) -> f64; }

// Define structs for each planet.
pub struct Mercury;
pub struct Venus;
pub struct Earth;
pub struct Mars;
pub struct Jupiter;
pub struct Saturn;
pub struct Uranus;
pub struct Neptune;

// A macro to generate implementations for each planet.
macro_rules! impl_planet
{
	($planet:ident, $factor:expr) =>
  {
		impl Planet for $planet
		{
			fn years_during(d: &Duration) -> f64
			{ (d.s as f64) / 31557600.0 / $factor }
		}
	};
}

// Use the macro to generate implementations.
impl_planet!(Mercury, 0.2408467);
impl_planet!(Venus, 0.61519726);
impl_planet!(Earth, 1.0);
impl_planet!(Mars, 1.8808158);
impl_planet!(Jupiter, 11.862615);
impl_planet!(Saturn, 29.447498);
impl_planet!(Uranus, 84.016846);
impl_planet!(Neptune, 164.79132);
