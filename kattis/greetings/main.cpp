/**
 * Greetings!
 * @see https://open.kattis.com/problems/greetings2
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

	char c;

	while (cin >> c)
	{
		if (c == 'e')
		{ cout << "ee"; }
		else
		{ cout << c; }
	}

	cout << '\n'

	return 0;
}
