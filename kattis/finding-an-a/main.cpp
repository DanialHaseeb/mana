/**
 * Finding an A
 * @see https://open.kattis.com/problems/findingana
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

	char letter;

	while (cin >> letter)
	{
		if (letter == 'a')
		{ break; }
	}

	do
	{ cout << letter; }
	while (cin >> letter);

	cout << '\n';

	return 0;
}
