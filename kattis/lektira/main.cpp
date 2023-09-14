/**
 * Lektira
 * @see https://open.kattis.com/problems/lektira
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string word;
	cin >> word;

	const auto size{ static_cast<long>(word.size()) };

	string best(50, 'z');

	for (long i{ 1 }; i < (size - 1); ++i)
	{
		for (long j{ i + 1 }; j < size; ++j)
		{
			string temp{ word };
			reverse(temp.begin(), temp.begin() + i);
			reverse(temp.begin() + i, temp.begin() + j);
			reverse(temp.begin() + j, temp.end());

			if (temp < best)
			{
				best = temp;
			}
		}
	}

	cout << best << '\n';

	return 0;
}
