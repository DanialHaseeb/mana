/**
 * Jack-O'-Lantern Juxtaposition
 * @see https://open.kattis.com/problems/jackolanternjuxtaposition
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
	int t;
	int m;

	cin >> n >> t >> m;

	cout << n * t * m << '\n';

	return 0;
}
