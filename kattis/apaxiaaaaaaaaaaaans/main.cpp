/**
 * Apaxiaaaaaaaaaaaans!
 * @see https://open.kattis.com/problems/apaxiaaans
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

	auto n{ name.length() };

	for (size_t i{ 0 }; i < n-1; ++i)
	{
		if (name[i] != name[i + 1])
		{ cout << name[i]; }
	}

	cout << name[n - 1] << '\n';

	return 0;
}
