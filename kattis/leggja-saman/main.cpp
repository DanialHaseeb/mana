/**
 * Leggja saman
 * @see https://open.kattis.com/problems/leggjasaman
 *
 * @author Danial Haseeb
 */

#include <iostream>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int m;
	cin >> n >> m;

	cout << n + m << '\n';

	return 0;
}
