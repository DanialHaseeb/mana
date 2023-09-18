/**
 * ABC
 * @see https://open.kattis.com/problems/abc
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <algorithm>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int integer1;
	int integer2;
	int integer3;

	cin >> integer1 >> integer2 >> integer3;

	const auto a{ min(min(integer1, integer2), integer3) };
	const auto c{ max(max(integer1, integer2), integer3) };
	const auto b{ integer1 + integer2 + integer3 - a - c };

	char letter;

	while (cin >> letter)
	{
		switch (letter)
		{
		case 'A':
			cout << a << ' ';
			break;
		case 'B':
			cout << b << ' ';
			break;
		case 'C':
			cout << c << ' ';
			break;
		}
	}

	return 0;
}
