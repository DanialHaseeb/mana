#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

auto isValid(const vector<int>& ruler) -> bool
{

	return true;
}

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string line{};

	while (getline(cin, line))
	{
		vector<int> ruler;

		stringstream inputStream{ line };
		int mark;

		while (inputStream >> mark)
		{ ruler.push_back(mark); }

		const auto size{ ruler.size() };
		const auto max{ *max_element(ruler.begin(), ruler.end()) };

		vector<int> occurences(max, 0);

		for (size_t i{ 0 }; i < size; ++i)
		{
			for (size_t j{ i + 1 }; j < size; ++j)
			{
				const auto distance{ static_cast<size_t>(abs(ruler[j] - ruler[i])) };
				occurences[distance] += 1;
			}
		}

		vector<size_t> missing;
		auto isValid{ true };
		auto isPerfect{ true};

		for (size_t distance{ 1 }; distance < size; ++distance)
		{
			if (occurences[distance] != 1)
			{ isPerfect = false; }

			if (occurences[distance] == 0)
			{
				isValid = false;
				missing.push_back(distance);
			}

		}
	}

	return 0;
}
