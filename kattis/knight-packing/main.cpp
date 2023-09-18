/**
 * Knight Packing
 * @see https://open.kattis.com/problems/knightpacking
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

	cout << ((n % 2 == 0) ? "second\n" : "first\n");

	return 0;
}
