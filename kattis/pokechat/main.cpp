/**
 * Pokechat
 * @see https://open.kattis.com/problems/pokechat
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto main() -> int
{
	// Input the two strings
	string s, ids;
	getline(cin, s);
	getline(cin, ids);

	const auto n{ ids.length() };

	// Extract numbers of length 3 from ids and use them as indices.
	vector<size_t> numbers;
	for (size_t i{ 0 }; i < n; i += 3)
	{
		const auto number{ stoi(ids.substr(i, 3)) };
		numbers.push_back(number - 1);
	}

	// Print the characters.
	for (const auto number : numbers)
	{ cout << s[number]; }

	cout << '\n';

	return 0;
}
