/**
 * Planina
 * @see https://open.kattis.com/problems/planina
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

	int n;
	cin >> n;

	n = (1 << n) + 1;
	n *= n;

	cout << n << '\n';

	return 0;
}
