/**
 * Selling Spatulas
 * @see https://open.kattis.com/problems/sellingspatulas
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <limits>
#include <array>
#include <iomanip>
#include <utility>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(2);

	constexpr size_t MAX{ 1440 };
	constexpr auto CPM{ 0.08 };

	// Read the number of test cases.
	int n;

	while (cin >> n)
	{
		if (n == 0)
		{ break; }

		array<double, MAX> profits{};
		profits.fill(-0.08);

		for (int i{}; i < n; ++i)
		{
			size_t time;
			double profit;

			cin >> time >> profit;

			profits[time] += profit;
		}

		auto bestStart{ MAX + 1 };
		auto bestDuration{ 1440 };
		auto bestProfit{ 0.0 };

		auto currentStart{ 0 };
		auto currentDuration{ -1 };
		auto currentProfit{ 0.0 };

		for (size_t i{ 0 }; i < MAX; ++i)
		{
			++currentDuration;
			currentProfit += profits[i];

			auto better{ currentProfit > bestProfit };
			[[maybe_unused]] auto equal{ currentProfit == bestProfit };
			[[maybe_unused]] auto sameDuration{ currentDuration == bestDuration };
			[[maybe_unused]] auto shorter{ currentDuration < bestDuration };
			[[maybe_unused]] auto earlier{ currentStart < bestStart };

			if (better or (equal and shorter) or (equal and sameDuration and earlier))
			{
				bestStart = currentStart;
				bestDuration = currentDuration;
				bestProfit = currentProfit;
			}

			if (currentProfit < 1e-9)
			{
				currentStart = i + 1;
				currentDuration = -1;
				currentProfit = 0.0;
			}
		}

		if (bestProfit < 1e-9)
		{ cout << "no profit\n"; }
		else
		{ cout << bestProfit << ' ' << bestStart << ' ' << bestStart + bestDuration << '\n'; }
	}

	return 0;
}
