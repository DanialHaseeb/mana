//
//  Encoded Message
//  https://open.kattis.com/problems/encodedmessage
//
//  Created by Danial Haseeb on 09/10/2023.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int tests;
	cin >> tests;

	for (int _{}; _ < tests; ++_)
	{
		string s;
		cin >> s;

		const auto n{ sqrt(s.size()) };

		vector<vector<char>> table(n, vector<char>(n));

		size_t index{ 0 };

		for (size_t i{ 0 }; i < n; ++i)
		{
			for (size_t j{ 0 }; j < n; ++j)
			{
				table[i][j] = s[index];
				++index;
			}
		}

		for (auto j{ n - 1 }; j >= 0; --j)
		{
			for(size_t i{ 0 }; i < n; ++i)
			{ cout << table[i][j]; }
		}

		cout << '\n';
	}

	return 0;
}
