/**
 * FizzBuzz
 * @see https://open.kattis.com/problems/fizzbuzz
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
	int n;

	cin >> x >> y >> n;

	for (int i{ 1 }; i <= n; ++i)
	{
		if (i % x == 0)
		{ cout << "Fizz"; }

		if (i % y == 0)
		{ cout << "Buzz"; }

		if ((i % x != 0) and (i % y != 0))
		{ cout << i; }

		cout << '\n';
	}

	return 0;
}
