/**
 * Zebras and Ocelots
 * Problem URL: https://open.kattis.com/problems/zebrasocelots
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

	long long N;
	cin >> N;

	char c;
	cin >> c;

	long long result{};

	if (c == 'Z')
	{ result = 0; }
	else
	{ result = 1; }

	for (long long i{}; i < (N - 1); ++i)
	{
		cin >> c;

		if (c == 'Z')
		{ result <<= 1; }
		else
		{
			result <<= 1;
			result += 1;
		}
	}

	cout << result << '\n';

	return 0;
}
