/**
 * Quality-Adjusted Life-Year
 * @see https://open.kattis.com/problems/qaly
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

	double qaly{ 0.0 };

	for (int i{}; i < n; ++i)
	{
		double q;
		double y;

		cin >> q >> y;

		qaly += (q * y);
	}

	cout << qaly << '\n';

	return 0;
}
