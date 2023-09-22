/**
 * A Different Problem
 * @see https://open.kattis.com/problems/different
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

	long long a;
	long long b;

	while (cin >> a >> b)
	{ cout << abs(a - b) << '\n'; }

	return 0;
}
