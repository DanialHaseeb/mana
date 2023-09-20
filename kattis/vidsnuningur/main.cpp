/**
 * Viðsnúningur
 * @see https://open.kattis.com/problems/vidsnuningur
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string text{};
	cin >> text;

	reverse(text.begin(), text.end());

	cout << text << '\n';

	return 0;
}
