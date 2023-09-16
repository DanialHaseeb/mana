/**
 * Stuck in a Time Loop
 * @see https://open.kattis.com/problems/timeloop
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

	for (int i{}; i < n; ++i)
	{ cout << i << " Abracadabra\n"; }

	return 0;
}
