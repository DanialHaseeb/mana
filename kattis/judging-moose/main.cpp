/**
 * Judging Moose
 * @see https://open.kattis.com/problems/judgingmoose
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

	int l;
	int r;

	cin >> l >> r;

	if (l == 0 && r == 0)
	{ cout << "Not a moose\n"; }
	else if (l == r)
	{ cout << "Even " << l + r << '\n'; }
	else
	{ cout << "Odd " << max(l, r) * 2 << '\n'; }

	return 0;
}
