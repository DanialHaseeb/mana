/**
 * Quadrant Selection
 * @see https://open.kattis.com/problems/quadrant
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

	int x;
	int y;

	cin >> x >> y;

	if (x > 0)
	{
		if (y > 0)
		{ cout << 1; }
		else
		{ cout << 4; }
	}
	else
	{
		if (y > 0)
		{ cout << 2; }
		else
		{ cout << 3; }
	}

	cout << '\n';

	return 0;
}
