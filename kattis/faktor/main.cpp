/**
 * Faktor
 * @see https://open.kattis.com/problems/faktor
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

	int a;
	int i;

	cin >> a >> i;

	cout << a * (i - 1) + 1 << '\n';

	return 0;
}
