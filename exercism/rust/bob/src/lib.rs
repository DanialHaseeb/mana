// Function to provide a reply based on the input `message`.
pub fn reply(message: &str) -> &str
{
	// Trim the message and match it against various conditions.
	match message.trim()
	{
		// Check for silence.
		"" => "Fine. Be that way!",
		// Check if yelling and a question.
		msg if is_yelling(msg) && is_question(msg) => "Calm down, I know what I'm doing!",
		// Check if yelling but not a question.
		msg if is_yelling(msg) => "Whoa, chill out!",
		// Check if a question but not yelling.
		msg if is_question(msg) => "Sure.",
		// Default case.
		_ => "Whatever."
	}
}

// Helper function to check if the message is a question.
fn is_question(message: &str) -> bool
{ message.chars().last() == Some('?') }

// Helper function to check if the message is yelling.
fn is_yelling(message: &str) -> bool
{
	let contains_alphabets = message.chars().any(|c| c.is_alphabetic());
	message.to_uppercase() == message && contains_alphabets
}
