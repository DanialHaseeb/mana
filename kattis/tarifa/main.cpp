/**
 * Tarifa
 * @see https://open.kattis.com/problems/tarifa
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

	int x;
	int n;

	cin >> x >> n;

	int p;

	auto sum{ x };

	for (int i{}; i < n; ++i)
	{
		cin >> p;
		sum += (x - p);
	}

	cout << sum << '\n';

	return 0;
}
