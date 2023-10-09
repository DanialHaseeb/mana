/**
 * Hissing Microphone
 * @see https://open.kattis.com/problems/hissingmicrophone
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

	auto s{ false };
	auto ss{ false };

	char letter;

	while (cin >> letter)
	{
		if (letter == 's')
		{
			if (s)
			{
				ss = true;
				break;
			}
			else
			{ s = true; }
		}
		else
		{ s = false; }
	}

	cout << (ss ? "hiss\n" : "no hiss\n");

	return 0;
}
