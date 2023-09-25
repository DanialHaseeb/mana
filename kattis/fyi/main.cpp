/**
 * FYI
 * @see https://open.kattis.com/problems/fyi
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

	char prefix;
	cin >> prefix;

	if (prefix == '5')
	{ cin >> prefix; }
	else
	{
		cout << "0\n";
		return 0;
	}

	if (prefix == '5')
	{ cin >> prefix; }
	else
	{
		cout << "0\n";
		return 0;
	}

	if (prefix == '5')
	{ cout << "1\n"; }
	else
	{
		cout << "0\n";
		return 0;
	}

	return 0;
}
