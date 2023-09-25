/**
 * Autori
 * @see https://open.kattis.com/problems/autori
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

	string name;
	cin >> name;
	const auto n{ name.length() };

	for (auto i = 0; i < n; ++i)
	{
		if (isupper(name[i]))
		{ cout << name[i]; }
	}

	return 0;
}
