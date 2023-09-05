#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

struct Hash
{
	auto operator()(const pair<int, int>& pair) const -> size_t
	{
		const auto x{ static_cast<size_t>(pair.first) };
		const auto y{ static_cast<size_t>(pair.second) };

		return (x << 32) | y;
	}
};

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Read the number of points.
	int n{};

	cin >> n;

	// Read the points.
	unordered_set<pair<int, int>, Hash> set;

	for (int i{}; i < n; ++i)
	{
		pair<int, int> point;

		cin >> point.first >> point.second;

		set.insert(point);
	}

	// Calculate offsets.
	vector<pair<int, int>> offsets;

	for (auto i{ -2018 }; i <= 2018; ++i)
	{
		for (auto j{ -2018 }; j <= 2018; ++j)
		{
			if (i*i + j*j == 2018*2018)
			{ offsets.push_back({ i, j }); }
		}
	}

	int result{ 0 };

	for (const auto& point : set)
	{
		for (const auto& [δx, δy] : offsets)
		{
			const auto& [x, y]{ point };
			const pair neighbour{ x+δx, y+δy };

			if (set.count(neighbour) > 0) // Can be replaced with set::contains in C++20.
			{ ++result; }
		}
	}

	// Divide by 2 because each pair of points is counted twice.
	cout << result / 2 << '\n';

	return 0;
}
