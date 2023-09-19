/**
 * Add Two Numbers
 * @see https://open.kattis.com/problems/addtwonumbers
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
	int b;

	cin >> a >> b;

	cout << a + b << '\n';

	return 0;
}
