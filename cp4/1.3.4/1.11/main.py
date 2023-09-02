import random

def exponentiate(base: int, exponent: int, modulus: int) -> int:
	"""
	Computes the result of base^exponent mod modulus.

	:param `base`: The base of the exponentiation.
	:param `exponent`: The exponent of the exponentiation.
	:param `modulus`: The modulus of the exponentiation.

	:returns: The result of `base`^`exponent` mod `modulus`.

	:complexity: O(log(`exponent`))
	"""
	accumulator = 1

	base %= modulus

	while (exponent > 0):
		if ((exponent % 2) != 0):
			accumulator = (accumulator * base) % modulus

		exponent //= 2

		base = (base ** 2) % modulus

	return accumulator

def miller_rabin(candidate_divisor: int, candidate_number: int) -> bool:
	"""
	Tests whether `candidate_number` is a prime number.

	:param `candidate_divisor`: A divisor of `candidate_number - 1`.
	:param `candidate_number`: The candidate number to be tested.

	:returns: `True` if candidate_number is a prime number, `False` otherwise.

	:complexity: O(log(`candidate_number`))
	"""
	random_base = 2 + random.randint(1, (candidate_number - 4))

	power_result = exponentiate(random_base, candidate_divisor, candidate_number)

	if ((power_result == 1) or (power_result == (candidate_number - 1))):
		return True

	while (candidate_divisor != (candidate_number - 1)):
		power_result = (power_result ** 2) % candidate_number

		candidate_divisor *= 2

		if (power_result == 1):
			return False

		if (power_result == (candidate_number - 1)):
			return True

	return False

def is_prime(candidate_number: int, test_iterations: int = 5) -> bool:
	"""
	Tests whether `candidate_number` is a prime number.

	:param `candidate_number`: The candidate number to be tested.
	:param `test_iterations`: The number of iterations to be performed.

	:returns: `True` if candidate_number is a prime number, `False` otherwise.

	:complexity: O(`test_iterations` * log(`candidate_number`))
	"""
	if ((candidate_number <= 1) or (candidate_number == 4)):
		return False

	if (candidate_number <= 3):
		return True

	candidate_divisor = candidate_number - 1

	while (candidate_divisor % 2 == 0):
		candidate_divisor //= 2

	for _ in range(test_iterations):
		if (not miller_rabin(candidate_divisor, candidate_number)):
			return False

	return True

# Example:
large_prime_candidate = 32416190071

if (is_prime(large_prime_candidate)):
	print("Prime")
else:
	print("Composite")
