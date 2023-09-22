/**
 * Roaming Romans
 * @see https://open.kattis.com/problems/romans
 *
 * @author Danial Haseeb
 */

#include <iostream>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double x;
	cin >> x;

	cout << static_cast<int>(x * (5280.0 / 4854.0) * 1000.0 + 0.5) << '\n';

	return 0;
}
