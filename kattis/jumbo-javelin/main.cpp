/**
 * Jumbo Javelin
 * @see https://open.kattis.com/problems/jumbojavelin
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

	int length;
	cin >> length;

	for (int i{}; i < (n - 1); ++i)
	{
		int l;
		cin >> l;

		length += (l - 1);
	}

	cout << length << '\n';

	return 0;
}
