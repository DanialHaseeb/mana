/**
 * Prozor
 * @see https://open.kattis.com/problems/prozor
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

auto countFlies(const vector<vector<bool>>& isFly, const pair<size_t, size_t>& start, const size_t k) -> int
{
	const auto& [x, y] = start;

	auto flies{ 0 };

	for (size_t i{ x + 1 }; i < (x + k - 1); ++i)
	{
		for (size_t j{ y + 1 }; j < (y + k - 1); ++j)
		{
			if (isFly[i][j])
			{ ++flies; }
		}
	}

	return flies;
}

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t r;
	size_t s;
	size_t k;

	cin >> r >> s >> k;

	vector<vector<bool>> isFly(r, vector<bool>(s, false));

	for (size_t i{}; i < r; ++i)
	{
		for (size_t j{}; j < s; ++j)
		{
			char pixel;
			cin >> pixel;

			isFly[i][j] = (pixel == '*');
		}
	}

	int maxKilled{};
	pair<size_t, size_t> bestStart;

	for (size_t i{}; i < r; ++i)
	{
		for (size_t j{}; j < s; ++j)
		{
			if ((i + k > r) or (j + k > s))
			{ continue; }

			const auto currentKilled{ countFlies(isFly, { i, j }, k) };

			if (currentKilled > maxKilled)
			{
				maxKilled = currentKilled;
				bestStart = { i, j };
			}
		}
	}

	cout << maxKilled << '\n';


	for (size_t i{}; i < r; ++i)
	{
		for (size_t j{}; j < s; ++j)
		{
			if ((i == bestStart.first) and (j == bestStart.second))
			{ cout << '+'; }
			else if ((i == bestStart.first) and (j == (bestStart.second + k - 1)))
			{ cout << '+'; }
			else if ((i == (bestStart.first + k - 1)) and (j == bestStart.second))
			{ cout << '+'; }
			else if ((i == (bestStart.first + k - 1)) and (j == (bestStart.second + k - 1)))
			{ cout << '+'; }
			else if ((i == bestStart.first) or (i == (bestStart.first + k - 1)))
			{
				if ((j > bestStart.second) and (j < (bestStart.second + k - 1)))
				{ cout << '-'; }
				else
				{ cout << (isFly[i][j] ? '*' : '.'); }
			}
			else if (j == bestStart.second or j == (bestStart.second + k - 1))
			{
				if ((i > bestStart.first) and (i < (bestStart.first + k - 1)))
				{ cout << '|'; }
				else
				{ cout << (isFly[i][j] ? '*' : '.'); }
			}
			else
			{ cout << (isFly[i][j] ? '*' : '.'); }
		}

		cout << '\n';
	}

	return 0;
}
