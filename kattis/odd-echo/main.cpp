/**
 * Odd Echo
 * @see https://open.kattis.com/problems/oddecho
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <string>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i{}; i < n; ++i)
	{
		string word{};
		cin >> word;

		if (i % 2 == 0)
		{ cout << word << '\n'; }
	}

	return 0;
}
