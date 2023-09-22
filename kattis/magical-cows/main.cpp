/**
 * Magical Cows
 * @see https://open.kattis.com/problems/magicalcows
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

using u64 = unsigned long long;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	u64 c;
	u64 n;
	u64 m;

	cin >> c >> n >> m;

	vector<u64> days;

	for (u64 i{ 0 }; i < n; i++)
	{
		u64 cows;
		cin >> cows;

		u64 day{ 0 };

		while (cows <= c)
		{
			++day;
			cows <<= 1;
		}

		days.push_back(day);
	}

	for (u64 i{ 0 }; i < m; ++i)
	{
		u64 d;
		cin >> d;

		u64 farms{ 0 };

		for (const auto day : days)
		{
			if (day > d)
			{ ++farms; }
			else
			{ farms += (static_cast<u64>(1) << d - day + static_cast<u64>(1)); }
		}

		cout << farms << '\n';
	}

	return 0;
}
