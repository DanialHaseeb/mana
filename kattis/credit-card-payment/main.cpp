/**
 * Credit Card Payment
 * @see https://open.kattis.com/problems/creditcard
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <cmath>
#include <algorithm> // for std::max

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// The maximum allowed error.
	const auto ε{ 1e-9 };

	/// The number of test cases.
	int tests{};

	cin >> tests;

	/// The maximum number of payments allowed.
	constexpr auto maxPayments{ 1200 };

	for (int i{}; i < tests; ++i)
	{
		/// The monthly interest rate (in dollars).
		double r{};

		/// The outstanding balance at the end of the month (in dollars).
		double b{};

		/// The monthly payment amount (in dollars).
		double m{};

		cin >> r >> b >> m;

		// Remove % sign from interest rate.
		r /= 100.0;

		auto payments{ 0 };

		while ((b > ε) and (payments <= maxPayments))
		{
			/// The monthly interest (in dollars).
			auto interest{ r * b };

			// Round interest to the nearest cent.
			interest = round(interest * 100.0) / 100.0;

			// Add this month's interest to the current balance.
			b += interest;

			// Round the current balance to the nearest cent.
			b = round(b * 100.0) / 100.0;

			// Subtract the monthly payment from the current balance.
			b -= m;

			// Round the current balance to the nearest cent.
			b = round(b * 100.0) / 100.0;

			// Increment the number of payments made.
			++payments;
		}

		if (payments > maxPayments)
		{ cout << "impossible\n"; }
		else
		{ cout << payments << '\n'; }
	}

	return 0;
}
