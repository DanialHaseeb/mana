/// The Luhn algorithm is used to validate credit card numbers.
///
/// # Arguments
/// * `code` - A string slice that holds the credit card number.
///
/// # Returns
/// A boolean value that indicates whether the credit card number is valid.
pub fn is_valid(code: &str) -> bool
{
  // The algorithm takes a string as input and does the following to validate
  // the credit card number:
  //   - Ignore all spaces. Reject number with less than two digits.
  //   - Moving from right to left, double every second digit:
  //       - for the number 1234, we double 3 and 1.
  //   - After doubling a digit, sum the digits.
  //     So doubling 7 becomes 14 which becomes 5.
  //   - Sum all the undoubled and doubled digits.
  //   - The credit card number is valid if the sum ends with 0.

  // Remove all spaces from the credit card number.
  let code = code.replace(" ", "");

  // Reject credit card numbers with less than two digits.
  if code.len() < 2
  { return false; }

  // Iterate over the credit card number from right to left.
  let mut sum = 0;
  let mut double = false;
  for c in code.chars().rev()
  {
    // Convert the character to a digit.
    if let Some(digit) = c.to_digit(10)
    {
      // Double every second digit.
      if double
      {
        let doubled = digit * 2;

        // Sum the digits of the doubled digit.
        sum += (doubled / 10) + (doubled % 10);
      }
      else
      { sum += digit; }

      // Toggle the double flag.
      double = !double;
    }
    else
    {
      // Reject credit card numbers with non-digit characters.
      return false;
    }
  }

  // The credit card number is valid if the sum ends with 0.
  sum % 10 == 0
}
