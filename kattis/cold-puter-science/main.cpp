/**
 * Cold-puter Science
 * @see https://open.kattis.com/problems/cold
 *
 * @author Danial Haseeb
 */

#include <iostream>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int count{};

	for (int i{}; i < n; ++i)
	{
		int t;
		cin >> t;

		if (t < 0)
		{ ++count; }
	}

	cout << count << '\n';

	return 0;
}
