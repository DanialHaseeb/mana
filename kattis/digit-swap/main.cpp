/**
 * Digit Swap
 * @see https://open.kattis.com/problems/digitswap
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

	char digit1;
	char digit2;

	cin >> digit1 >> digit2;

	cout << digit2 << digit1 << '\n';

	return 0;
}
