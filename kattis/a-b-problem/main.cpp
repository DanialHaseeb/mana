/**
 * A+B Problem
 * @see https://open.kattis.com/problems/aplusb
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <vector>
#include <complex>
#include <algorithm>
#include <numbers>
#include <array>

using namespace std;

using Int = long long int;
using Complex = complex<double>;

constexpr auto π = 3.14159265358979323846;

constexpr auto MIN{ -50000 };
constexpr auto MAX{ +50000 };

constexpr auto SHIFT{ static_cast<size_t>(1 - MIN) };
constexpr auto SIZE{ static_cast<size_t>(MAX + SHIFT + 1) };

/** The maximum number of bits required to represent the input.
 *
 * This is calculated as the smallest power of 2 greater than the maximum
 * possible sum of two inputs, i.e., ceil(log_2(2*SIZE)).
 */
constexpr size_t LOG_BOUND{ 18 };
constexpr size_t BOUND{ 1 << LOG_BOUND };

constexpr size_t MAX_FREQUENCY{ 200'000 };
constexpr size_t MAX_COEFFICIENT{ 2 * MAX_FREQUENCY };

array<Complex, MAX_COEFFICIENT> root{};
array<Complex, MAX_COEFFICIENT> phase{};
array<size_t, MAX_COEFFICIENT> permutations{};

auto fft(array<Complex, MAX_COEFFICIENT>& signal)
{
	for(size_t i{ 0 }; i < BOUND; i++)
	{
		if (i < permutations[i])
		{ swap(signal[i], signal[permutations[i]]); }
	}

	for(size_t length{ 1 }; length < BOUND; length *= 2)
	{
		for(size_t position{ 0 }; position < BOUND; position += (2*length))
		{
			for(size_t i{ 0 }; i < length; ++i)
			{
				const auto POSITION{ position + i };
				const auto ROOT{ static_cast<size_t>(BOUND / length / 2 * i) };

				const auto x{ signal[POSITION] };
				const auto y{ signal[POSITION + length] * root[ROOT] };

				signal[POSITION] = x + y;
				signal[POSITION + length] = x - y;
			}
		}
	}
}

auto square(const array<Int, SIZE>& p) -> vector<Int>
{
	array<Complex, MAX_COEFFICIENT> signal{};

	for (size_t i{ 0 }; i < BOUND; ++i)
	{ signal[i] = (i < SIZE) ? Complex(static_cast<double>(p[i]), 0) : Complex(0, 0); }

	fft(signal);

	for (size_t i{ 0 }; i < BOUND; ++i)
	{ signal[i] *= signal[i]; }

	fft(signal);

	reverse(signal.begin() + 1, signal.begin() + BOUND);

	vector<Int> coefficients(BOUND);

	for (size_t i{ 0 }; i < BOUND; ++i)
	{
		signal[i] /= BOUND;

		const auto real = signal[i].real();
		const auto cofficient = (real > 0) ? real + 0.5 : real - 0.5;

		coefficients[i] = static_cast<Int>(cofficient);
	}

	while ((not coefficients.empty()) and (coefficients.back() == 0))
	{	coefficients.pop_back(); }

	return coefficients;
}

/**
 * The key idea behind this approach is representing the frequencies of numbers
 * as coefficients of a polynomial. When we multiply two such polynomials, the
 * coefficient of x^k in the resulting polynomial represents the number of pairs
 * (i,j) such that i + j = k.
 */
auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t n;
	cin >> n;

	size_t zeroes{ 0 };
	array<Int, SIZE> frequencies{};
	vector<size_t> a(n);

	// Read input.
	for (size_t i{ 0 }; i < n; ++i)
	{
		Int input;
		cin >> input;

		if (input == 0)
		{ ++zeroes; }

		/*
		 * Shift the input by to make it positive.
		 *
		 * We already know the minimum possible value of the input is -50000.  So,
		 * we shift each input by 50001 to make all values positive.
		 *
		 * This is done because the FFT algorithm requires the input to be positive.
		 * When using arrays to store coefficients, negative indices would result in
		 * out-of-bounds memory access, which is not permissible.
		 */
		input += static_cast<int>(SHIFT);

		a[i] = static_cast<size_t>(input);

		// Increment the frequency of the input integer.
		++frequencies[a[i]];
	}

	Int msb{ -1 };
	root[0] = 1;

	constexpr auto θ{ 2.0 * π / static_cast<double>(BOUND) };

	for(size_t i{ 1 }; i < BOUND; ++i)
	{
		// If i is a power of 2:
		if ((i & (i - 1)) == 0)
		{	++msb; }

		const auto MSB{ static_cast<size_t>(msb) };

		root[i] = Complex(cos(i*θ), sin(i*θ));
		permutations[i] = permutations[i ^ (1 << MSB)] + (1 << (LOG_BOUND - MSB - 1));
	}

	auto results{ square(frequencies) };

	// For each number, remove it added to itself (basically, don't allow i+i=k. only i+j=k)
	for (const auto a_i : a)
	{ --results[2 * a_i]; }

	// Answer - for each number in the input, add the number of ways
	// we can add two numbers to get it
	Int result { 0 };

	for (const auto a_i : a)
	{ result += results[a_i + SHIFT]; }

	// Remove the number of ways zeros can be added to all other numbers
	result -= 2LL * zeroes * (n-1);

	cout << result << '\n';
}
