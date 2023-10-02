/**
 * Bela
 * @see https://open.kattis.com/problems/bela
 *
 * @author Danial Haseeb
 */

#include <iostream>

using namespace std;

auto value(char rank) -> int
{
	switch (rank)
	{
		case 'A': return 11;
		case 'K': return 4;
		case 'Q': return 3;
		case 'J': return 2;
		case 'T': return 10;

		default: return 0;
	}
}

auto dominantValue(char rank) -> int
{
	switch (rank)
	{
		case 'A': return 11;
		case 'K': return 4;
		case 'Q': return 3;
		case 'J': return 20;
		case 'T': return 10;
		case '9': return 14;

		default: return 0;
	}
}

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	char b;

	cin >> n >> b;

	int points{ 0 };

	for (int i{}; i < 4*n; ++i)
	{
		char rank;
		char suit;

		cin >> rank >> suit;

		points += (suit == b) ? dominantValue(rank) : value(rank);
	}

	cout << points << '\n';

	return 0;
}
