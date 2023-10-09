/**
 * Eye of Sauron
 * @see https://open.kattis.com/problems/eyeofsauron
 *
 * @author Danial Haseeb
 */

#include <ios>
#include <iostream>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	char character;

	int left{ 0 };

	while (true)
	{
		cin >> character;

		if (character == '(')
		{ break; }

		++left;
	}

	cin >> character;

	int right{ 0 };

	while (cin >> character)
	{ ++right; }

	cout << (left == right ? "correct\n" : "fix\n");

	return 0;
}
