/// Calculates the Collatz sequence starting from a given number `n`.
///
/// Returns `None` if `n` is 0 or if overflow occurs during calculation.
/// Otherwise, returns `Some(x)` where `x` is the number of steps to reach 1.
pub fn collatz(n: u64) -> Option<u64>
{
	// Return `None` if the input number is zero.
	if n == 0
	{ return None; }

	// Initialize a counter for the number of steps in the sequence.
	let mut x = 0;

	let mut n = n;

	// Continue until the sequence reaches the number 1.
	while n != 1
	{
		// If `n` is even, divide it by 2.
		if n % 2 == 0
		{ n /= 2; }
		else
		{
			// If `n` is odd, multiply it by 3 and add 1.
			// Use checked arithmetic to avoid overflow.
			if let Some(new_n) = n.checked_mul(3)
			{
				if let Some(new_n) = new_n.checked_add(1)
				{ n = new_n; }
				else
				{
					// Return `None` in case of overflow.
					return None;
				}
			}
			else
			{
				// Return `None` in case of overflow.
				return None;
			}
		}

		// Increment the step counter.
		x += 1;
	}

	// Return the total number of steps to reach 1.
	Some(x)
}
