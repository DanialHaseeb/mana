/**
 * Óvissa
 * @see https://open.kattis.com/problems/ovissa
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

	char input;

	auto uncertainty{ 0 };

	while (cin >> input)
	{
		if (input == 'u')
		{ ++uncertainty; }
	}

	cout << uncertainty << '\n';

	return 0;
}
