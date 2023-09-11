/**
 * Knigs of the Forest
 * @see https://open.kattis.com/problems/knigsoftheforest
 *
 * @author Danial Haseeb
*/

#include <iostream>
#include <queue>
#include <map>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// The size of the tournament pool.
	int k;

	/// The number of years for which you have been supplied sufficient information.
	int n;

	// Read the input.
	cin >> k >> n;

	/// Karl-Älgtav's year of entry.
	int y;

	/// Karl-Älgtav's strength.
	int p;

	// Read the input.
	cin >> y >> p;

	/// A map of the years of entry to the strengths of the moose.
	map<int, int> moose;

	/// Tournament priority queue.
	priority_queue<int> queue;

	if (y == 2011)
	{ queue.push(p); }
	else
	{ moose[y] = p; }

	for (int i{}; i < (n + k -2); ++i)
	{
		int year;
		int strength;

		// Read the input.
		cin >> year >> strength;

		if (year == 2011)
		{ queue.push(strength); }
		else
		{ moose[year] = strength; }
	}

	// Simulate 2011.
	int year{ 2011 };
	int winner{ queue.top() };

	if (winner == p)
	{
		cout << year << '\n';
		return 0;
	}

	queue.pop();

	gameLoop: for (const auto& [_, strength] : moose)
	{
		++year;
		queue.push(strength);
		winner = queue.top();

		if (winner == p)
		{ break; }

		queue.pop();
	}

	if (winner == p)
	{ cout << year << '\n'; }
	else
	{ cout << "unknown\n"; }

	return 0;
}
