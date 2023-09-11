/**
 * Memory Match
 * @see https://open.kattis.com/problems/memorymatch
 *
 * @author Danial Haseeb
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// The number of cards on the table (2 – 1000).
	int n{};
	/// The number of turns played thus far in the game (0 – 1000).
	int k{};

	cin >> n >> k;

	/// A dictionary that contains card names and their known positions.
	unordered_map<string, unordered_set<int>> cardPositions;

	/// The number of cards that have already been paired.
	int paired{};

	for (int i{}; i < k; ++i)
	{
		int c1{};
		int c2{};
		string p1{};
		string p2{};

		cin >> c1 >> c2 >> p1 >> p2;

		// Record the positions of the cards revealed in this turn
		cardPositions[p1].insert(c1);
		cardPositions[p2].insert(c2);

		// If the revealed cards in this turn are a match, increment the paired count
		if (p1 == p2)
		{ ++paired; }
	}

	// The number of cards that can possibly be paired with current knowledge.
	int pairable{};
	for (const auto& [ _, positions] : cardPositions)
	{
		// If we know both positions of a card, it can be paired
		if (positions.size() == 2)
		{ ++pairable; }
	}

	/// The number of unique cards in the game.
	const auto uniqueCards{ n / 2 };

	/// The number of unique cards you have seen so far in the game.
	const auto seenCards{ cardPositions.size() };

	/// Flag indicating whether all cards have been seen.
	const auto seenAllCards = (seenCards == uniqueCards);

	/// Flag indicating whether only a single pair remains unpaired.
	const auto singlePairRemains = (pairable == uniqueCards - 1);

	// If all cards have been seen or only a single pair remains unknown,
	// then all remaining pairs can be scored with certainty.

	/// The number of matching pairs that can be scored with certainty.
	auto s{ seenAllCards or singlePairRemains ? uniqueCards : pairable };
	s -= paired;

	// Output the result.
	cout << s << '\n';

	return 0;
}
