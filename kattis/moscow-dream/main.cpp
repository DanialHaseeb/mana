/**
 * Moscow Dream
 * @see https://open.kattis.com/problems/moscowdream
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
	int c;
	int n;

	cin >> a >> b >> c >> n;

	cout << ((a >= 1 && b >= 1 && c >= 1 && a + b + c >= n && n >= 3) ? "YES" : "NO")
	     << '\n';

	return 0;
}
