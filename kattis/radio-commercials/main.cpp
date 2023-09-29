/**
 * Radio Commercials
 * @see https://open.kattis.com/problems/commercials
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <vector>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t n;
	int p;

	cin >> n >> p;

	vector<int> partialSums(n);

	for (size_t i{}; i < n; ++i)
	{
		cin >> partialSums[i];
		partialSums[i] -= p;
	}

	int sumSoFar{};
	int overall{};

	for (size_t i{}; i < n; ++i)
	{
		sumSoFar = max(0,sumSoFar + partialSums[i]);
		overall = max(overall,sumSoFar);
	}

	cout << overall << '\n';

	return 0;
}
