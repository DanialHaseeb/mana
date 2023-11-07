/**
 * Network Traffic Monitoring
 *
 * @author Team DRS
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	int θ;
	cin >> t >> θ;
	for (int _{ 0 }; _ < t; ++_)
	{
		size_t n;
		cin >> n;

		vector<int> packets(n);
		for (size_t i{ 0 }; i < n; ++i)
		{ cin >> packets[i]; }

		vector<int> dd1(n - 1);
		for(size_t i{ 0 }; i < n-1; ++i)
		{ dd1[i] = abs(packets[i] - packets[i+1]); }

		vector<int> dd2(n - 2);
		for(size_t i{ 0 }; i < n-2; ++i)
		{ dd2[i] = abs(dd1[i] - dd1[i+1]); }

		string result{};
		for(size_t i{ 0 }; i < n-2; ++i)
		{
			if (dd2[i]>= θ)
			{ result += "1 "; }
			else
			{ result += "0 "; }
		}
		result.pop_back();

		cout << result << '\n';
	}

	return 0;
}
