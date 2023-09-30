/**
 * Detailed Differences
 * @see https://open.kattis.com/problems/detaileddifferences
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

	int n;
	cin >> n;

	for (int i{}; i < n; ++i)
	{
		string string1;
		string string2;

		cin >> string1 >> string2;

		cout << string1 << '\n' << string2 << '\n';

		for (size_t j{}; j < string1.length(); ++j)
		{
			if (string1[j] == string2[j])
			{ cout << '.'; }
			else
			{ cout << '*'; }
		}

		cout << "\n\n";
	}

	return 0;
}
