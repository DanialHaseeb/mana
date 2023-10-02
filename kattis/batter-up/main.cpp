/**
 * Batter Up
 * @see https://open.kattis.com/problems/batterup
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <iomanip>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	auto total{ 0.0 };
	auto count{ 0.0 };

	for (int i{}; i < n; ++i)
	{
		int atBat;
		cin >> atBat;

		if (atBat != -1)
		{
			total += atBat;
			++count;
		}
	}

	cout << fixed << setprecision(9) << total / count << '\n';

	return 0;
}
