/**
 * Dance Recital
 * @see https://open.kattis.com/problems/dancerecital
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <vector>
#include <string>
#include <string_view>
#include <algorithm>
#include <limits>
#include <utility>

using namespace std;

auto countQuickChanges(string_view routine1, string_view routine2) -> int
{
	auto n{ routine1.size() };
	auto m{ routine2.size() };

	size_t dancer1{ 0 };
	size_t dancer2{ 0 };

	int quickChanges{ 0 };

	while ((dancer1 < n) and (dancer2 < m))
	{
		if (routine1[dancer1] == routine2[dancer2])
		{
			++quickChanges;
			++dancer1;
			++dancer2;
		}
		else if (routine1[dancer1] < routine2[dancer2])
		{ ++dancer1; }
		else
		{ ++dancer2; }
	}

	return quickChanges;
}

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// The number of routines in the recital.
	size_t r;
	cin >> r;

	/// The number of subsets of r routines, i.e., 2^r.
	const auto subsets{ static_cast<size_t>(1) << r };

	vector<string> routines(r);

	vector<vector<int>> quickChanges(r, vector<int>(r));

	for (size_t i{ 0 }; i < r; ++i)
	{ cin >> routines[i]; }

	// Compute quick changes for all pairs
	for (size_t i{ 0 }; i < r; ++i)
	{
		for (size_t j{ i + 1 }; j < r; ++j)
		{
			quickChanges[i][j] = countQuickChanges(routines[i], routines[j]);
			quickChanges[j][i] = quickChanges[i][j];
		}
	}

	// Initialize dp to a large value.
	vector<vector<int>> dp(subsets, vector<int>(r, numeric_limits<int>::max()));

	/*
	 * Base cases occur when there is only one routine selected.  In this case,
	 * there are no quick changes necessary.
	 *
	 * Setting the mask to 1 << i (i.e., 2^i) means that only routine i is
	 * selected (since only the ith bit is turned on).
	 */
	for(size_t i{ 0 }; i < r; ++i)
	{
		const auto mask{ static_cast<size_t>(1) << i };
		dp[mask][i] = 0;
	}

	// Dynamic programming using bitmasking.
	for (size_t currentRoutines{ 0 }; currentRoutines < subsets; ++currentRoutines)
	{
		for (size_t current{ 0 }; current < r; ++current)
		{
			const auto selectedCurrent{ (currentRoutines & (1 << current)) != 0 };

			if (selectedCurrent)
			{
				for (size_t next{ 0 }; next < r; ++next)
				{
					const auto selectedNext{ (currentRoutines & (1 << next)) != 0 };

					if (not selectedNext)
					{
						const auto nextRoutines{ currentRoutines | (1 << next) };
						const auto candidate{ dp[currentRoutines][current] + quickChanges[current][next] };

						dp[nextRoutines][next] = min(dp[nextRoutines][next], candidate);
					}
				}
			}
		}
	}

	int minQuickChanges = numeric_limits<int>::max();

	for (size_t i{ 0 }; i < r; ++i)
	{
		const auto selected{ (static_cast<size_t>(1) << r) - 1 };
		minQuickChanges = min(minQuickChanges, dp[selected][i]);
	}

	cout << minQuickChanges << '\n';

	return 0;
}
