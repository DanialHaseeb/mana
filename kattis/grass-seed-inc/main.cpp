/**
 * Grass Seed Inc.
 * @see https://open.kattis.com/problems/grassseed
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

	double c;
	int l;

	cin >> c >> l;

	auto area{ 0.0 };

	for (int i{}; i < l; ++i)
	{
		double w;
		double l;

		cin >> w >> l;

		area += (w * l);
	}

	cout.precision(10);
	cout << fixed << area * c << '\n';

	return 0;
}
