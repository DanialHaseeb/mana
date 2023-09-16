/**
 * R2
 * @see https://open.kattis.com/problems/r2
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

	int r1;
	int s;

	cin >> r1 >> s;

	cout << (2*s) - r1 << '\n';

	return 0;
}
