/**
 * Geppetto
 * @see https://open.kattis.com/problems/geppetto
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <unordered_set>
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

	int n;
	int m;

	cin >> n >> m;

	unordered_set<pair<int, int>, Hash> set;

	auto result{ 1 << n };

	for (int i{}; i < m; ++i)
	{
		int a;
		int b;

		cin >> a >> b;

		set.insert({ a, b });
	}

	for (int i{}; i < (1 << n); ++i)
	{
		for (const auto& [a, b] : set)
		{
			auto hasBoth{ (1 << (a - 1)) | (1 << (b - 1)) };

			if ((i & hasBoth) == hasBoth)
			{
				--result;
				break;
			}
		}
	}

	cout << result << '\n';

	return 0;
}
