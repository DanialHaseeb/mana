/**
 * Competitive Prgoramming 4
 *
 * 1.3.4.1.6
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	auto n{ 5 };
	auto v{ 7 };
	array L{ 10, 7, 5, 20, 8 };

	sort(L.begin(), L.end());

	cout << binary_search(L.begin(), L.end(), v) << '\n';

	return 0;
}
