/**
 * Free Weights
 * @see https://open.kattis.com/problems/freeweights
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <unordered_map>
#include <optional>
#include <vector>

using namespace std;

auto valid(const vector<size_t>& row, size_t threshold) -> bool
{
	optional<size_t> target{ nullopt };

	for (const auto& weight : row)
	{
		if (weight >= threshold)
		{
			if (target.has_value())
			{
				if (target.value() != weight)
				{ return false; }

				target.reset();
			}
			else
			{ target = weight; }
		}
	}

	return not (target.has_value());
}

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t n;
	cin >> n;

	vector<size_t> row1(n);
	vector<size_t> row2(n);
	unordered_map<size_t, size_t> map;

	for(auto& i : row1)
	{
		cin >> i;
		++map[i];
	}

	for (auto& i : row2)
	{ cin >> i; }

	size_t low{ 0 };
	size_t high{ 1'000'000'000 };
	size_t mid{ (high + low) / 2 };

	/*
	 * For weights that only appear once in either of the rows, the program sets
	 * the lower bound of the binary search to the maximum of such weights.
	 *
	 * This is because, at the minimum, you'd need to be able to lift these
	 * weights to pair them.
	 */
	for (const auto& [key, value] : map)
	{
		if (value == 1)
		{ low = (low > key) ? low : key; }
	}

	while ((high - low) > 1)
	{
		mid = (high + low) / 2;

		if (valid(row1, mid) and valid(row2, mid))
		{ high = mid; }
		else
		{ low = mid; }
	}

	cout << low << '\n';

	return 0;
}
