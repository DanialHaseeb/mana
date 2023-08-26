use std::fmt::{Display, Formatter, Result};

/// Represents a 24-hour clock with hours and minutes.
#[derive(Debug)]
pub struct Clock
{
	hours: i32,
	minutes: i32
}

impl Clock
{
	/// Constructs a new `Clock` with given `hours` and `minutes`.
	///
	/// Adjusts the time to fit into a 24-hour clock format.
	pub fn new(hours: i32, minutes: i32) -> Self
	{
		let mut hours = hours;
		let mut minutes = minutes;

		// Adjust minutes and hours if they don't fit into the standard 24-hour clock format.
		if !(0..60).contains(&minutes)
		{
			hours += minutes.div_euclid(60);
			minutes = minutes.rem_euclid(60);
		}

		if !(0..24).contains(&hours)
		{ hours = hours.rem_euclid(24); }

		Clock { hours, minutes }
	}

	/// Adds the given number of `minutes` to the current `Clock` time.
	///
	/// Returns a new `Clock` with the updated time.
	pub fn add_minutes(&self, minutes: i32) -> Self
	{
		let mut hours = self.hours;
		let mut minutes = self.minutes + minutes;

		// Adjust minutes and hours if they don't fit into the standard 24-hour clock format.
		if !(0..60).contains(&minutes)
		{
			hours += minutes.div_euclid(60);
			minutes = minutes.rem_euclid(60);
		}

		if !(0..24).contains(&hours)
		{ hours = hours.rem_euclid(24); }

		Clock::new(hours, minutes)
	}
}

/// Implements the `Display` trait for the `Clock` struct.
impl Display for Clock
{
	fn fmt(&self, f: &mut Formatter) -> Result
	{
		// Formats the clock time as a string in the form "HH:MM".
		write!(f, "{:02}:{:02}", self.hours, self.minutes)
	}
}

/// Implements the `PartialEq` trait for the `Clock` struct.
impl PartialEq for Clock
{
	fn eq(&self, other: &Self) -> bool
	{
		// Creates new `Clock` instances for self and other, then compares them.
		let left = Clock::new(self.hours, self.minutes);
		let right = Clock::new(other.hours, other.minutes);

		// Checks if the hours and minutes of both clocks are equal.
		(left.hours == right.hours) && (left.minutes == right.minutes)
	}
}
