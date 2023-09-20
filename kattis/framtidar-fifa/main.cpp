/**
 * Framtíðar FIFA
 * @see https://open.kattis.com/problems/fifa
 *
 * @author Danial Haseeb
 */

#include <iostream>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	int k;

	cin >> n >> k;

	cout << 2022 + (n / k) << '\n';

	return 0;
}
