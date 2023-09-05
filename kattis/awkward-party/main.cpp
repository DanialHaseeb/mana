#include <iostream>
#include <unordered_map>
#include <cstddef>
#include <algorithm>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t n;
	cin >> n;

	unordered_map<size_t, vector<size_t>> map;

	for (size_t i{}; i < n; ++i)
	{
		int x;
		cin >> x;

		map[x].push_back(i);
	}

	auto result{ n };

	for (const auto& [_, speakers] : map)
	{
		for (size_t j{ 1 }; j < speakers.size(); ++j)
		{
			const auto awkwardness{ speakers[j] - speakers[j - 1] };
			result = min(result, awkwardness);
		}
	}

	cout << result << '\n';

	return 0;
}
