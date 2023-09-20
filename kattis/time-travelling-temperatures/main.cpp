/**
 * Time Travelling Temperatures
 * @see https://open.kattis.com/problems/temperature
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <iomanip>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// The point on `B` where `A` is zero.
	int x{};

	/// The number of degrees in `B` that equal a change of a single degree in `A`.
	int y{};

	cin >> x >> y;

	// Special case: if y = 1 and x = 0, all temperatures are good
	if ((y == 1) and (x == 0))
	{
		cout << "ALL GOOD";
		return 0;
	}

	// Special case: if y = 1 and x != 0, the temperatures will never be equal
	if (y == 1)
	{
		cout << "IMPOSSIBLE";
		return 0;
	}

	/**
	 * The temperature at which the two time machines give the same reading.
	 *
	 * The formula is derived from the equation x + y * t = t, which simplifies to
	 * t = x / (1 - y).
	 */
	const auto sameTemperature = static_cast<double>(x) / (1.0 - static_cast<double>(y));

	// Set output precision to 9 decimal places
	cout.precision(9);

	// Output the calculated temperature with fixed-point notation
	cout << fixed << sameTemperature << '\n';

	return 0;
}
