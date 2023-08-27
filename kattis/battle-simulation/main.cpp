/**
 * Battle Simulation
 * @see https://open.kattis.com/problems/battlesimulation
 *
 * @author Danial Haseeb
*/

#include <iostream>
#include <unordered_map>
#include <deque>

using namespace std;

/**
 * This function checks if the last three moves form a combo.
 * A combo is formed when the last three moves are all distinct.
 *
 * @param moves: A deque containing the sequence of moves.
 * @return: true if a combo is formed, false otherwise.
 */
auto combo(const deque<char> moves) -> bool
{
	// Check if there are enough moves to form a combo
	if (moves.size() < 3)
	{ return false; }

	// Check if the last three moves are distinct
	return
		moves[0] != moves[1]
		and
		moves[1] != moves[2]
		and
		moves[0] != moves[2];
}

/**
 * Main function of the program.
 * This program takes a sequence of moves and returns the sequence of counters.
 * Moves can be one of 'R', 'B', 'L'.
 * Each move has a specific counter: 'R'->'S', 'B'->'K', 'L'->'H'.
 * A combo is formed when the last three moves are distinct, and it's countered by 'C'.
 *
 * @return: 0 on successful execution.
 */
auto main() -> int
{
	// Optimise I/O operations
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	// Mapping each move to its counter
	unordered_map<char, char> counters
	{ {'R', 'S'}, {'B', 'K'}, {'L', 'H'} };

	// Deque to store the sequence of moves
	deque<char> moves;

	char move{};

	// Read each move from standard input
	while (cin >> move)
	{
		// Add the move to the deque
		moves.push_back(move);

		// If there are not enough moves to form a combo, continue to the next iteration
		if (moves.size() < 3)
		{ continue; }

		// Check for a combo
		if (combo(moves))
		{
			cout << 'C';

			// Remove the last three moves that formed the combo
			moves.pop_front();
			moves.pop_front();
			moves.pop_front();
		}
		else
		{
			// Output the counter for the oldest move and remove it from the deque
			cout << counters[moves.front()];
			moves.pop_front();
		}
	}

	// Check for a combo with the remaining moves
	if (combo(moves))
	{
		cout << 'C';
		return 0;
	}

	// Output counters for any remaining moves
	while (not moves.empty())
	{
		cout << counters[moves.front()];
		moves.pop_front();
	}

	// Print a newline character at the end
	cout << '\n';

	return 0;
}
