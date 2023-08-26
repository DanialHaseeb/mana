/// Generates a private key `a` for the Diffie-Hellman key exchange.
///
/// In this implementation, the private key is always 2.
pub fn private_key(p: u64) -> u64
{ 2 }

/// Generates a public key `A` using the base `g`, private key `a`, and the prime `p`.
pub fn public_key(p: u64, g: u64, a: u64) -> u64
{
	// Use modular exponentiation to calculate the public key.
	modular_pow(g, a, p)
}

/// Calculates a shared secret `s` using the public key `B` from the other party,
/// the private key `a`, and the prime `p`.
pub fn secret(p: u64, b_pub: u64, a: u64) -> u64
{
	// Use modular exponentiation to calculate the shared secret.
	modular_pow(b_pub, a, p)
}

/// Computes using the binary exponentiation algorithm.
fn modular_pow(base: u64, exponent: u64, modulus: u64) -> u64
{
	// If the modulus is 1, the result is always 0.
	if modulus == 1
	{ return 0; }

	let mut result = 1;
	let mut base = base % modulus;
	let mut exponent = exponent;

	// Use binary exponentiation to efficiently calculate the result.
	while exponent > 0
	{
		if exponent % 2 == 1
		{ result = (result * base) % modulus; }
		exponent >>= 1;
		base = (base * base) % modulus;
	}

	result
}
