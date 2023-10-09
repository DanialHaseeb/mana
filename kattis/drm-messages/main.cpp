//
//  DRM Messages
//  https://open.kattis.com/problems/drmmessages
//
//  Created by Danial Haseeb on 09/10/2023.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string encryption;
	cin >> encryption;

	const auto half = encryption.length() / 2;

	string firstSplit = encryption.substr(0, half);
	string secondSplit = encryption.substr(half);

	auto position1{ 0 };
	auto position2{ 0 };

	vector<int> alphabet1(half);
	vector<int> alphabet2(half);

	for (size_t x{ 0 }; x < half; ++x)
	{
		position1 = (position1 + (firstSplit[x] - 'A')) % 26;
		alphabet1[x] = firstSplit[x] - 'A';

		position2 = (position2 + (secondSplit[x] - 'A')) % 26;
		alphabet2[x] = secondSplit[x] - 'A';
	}

	string merge = "";

	for (size_t s{ 0 }; s < half; ++s)
	{
		const auto rotated1 = (alphabet1[s] + position1) % 26;
		const auto rotated2 = (alphabet2[s] + position2) % 26;
		const auto newPosition = (rotated1 + rotated2) % 26;
		merge += ('A' + newPosition);
	}

	cout << merge << '\n';

	return 0;
}
