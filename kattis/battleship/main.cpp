/**
 * Battleship
 * @see https://open.kattis.com/problems/battleship
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Check if the given deployment map has any ships left.
 *
 * @param map The deployment map to check.
 *
 * @return True if the given deployment map has any ships left, false otherwise.
 */
auto hasShips(const vector<vector<bool>>& map) -> bool
{
	for (const auto row : map)
	{
		for (const auto ship : row)
		{
			if (ship)
			{ return true; }
		}
	}

	return false;
}

/**
 * Check if the given shot hits a ship.
 *
 * @param ships The deployment map to shoot at.
 * @param shot The coordinates of the shot.
 *
 * @return True if a ship was hit, false otherwise.
*/
auto isHit(const pair<size_t, size_t>& shot, vector<vector<bool>>& ships)
-> bool
{
	/// The coordinates of the shot.
	auto [x, y]{ shot };

	// Convert the coordinates to the correct format.
	y = (ships.size() - 1) - y;

	if (ships[y][x])
	{
		ships[y][x] = false;
		return true;
	}

	return false;
}

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// The number of test cases.
	int t{};

	cin >> t;

	for (int i{}; i < t; ++i)
	{
		/// The width of the fleet deployment maps.
		size_t w{};

		/// The height of the fleet deployment maps.
		size_t h{};

		/// The number of shots.
		size_t n{};

		cin >> w >> h >> n;

		/// The deployment map for player one.
		vector<vector<bool>> ships1(h, vector<bool>(w));

		/// The deployment map for player two.
		vector<vector<bool>> ships2(h, vector<bool>(w));

		// Read the deployment map for player one.
		for (size_t j{}; j < h; ++j)
		{
			for (size_t k{}; k < w; ++k)
			{
				char symbol{};

				cin >> symbol;

				if (symbol == '#')
				{ ships1[j][k] = true; }
			}
		}

		// Read the deployment map for player two.
		for (size_t j{}; j < h; ++j)
		{
			for (size_t k{}; k < w; ++k)
			{
				char symbol{};

				cin >> symbol;

				if (symbol == '#')
				{ ships2[j][k] = true; }
			}
		}

		/// The shot orders.
		vector<pair<size_t, size_t>> shots(n);

		// Read the shot orders.
		for (size_t j{}; j < n; ++j)
		{ cin >> shots[j].first >> shots[j].second; }

		/// A flag indicating whether player one is the current player.
		auto turnPlayer1{ true };

		for (const auto& shot : shots)
		{
			if (turnPlayer1)
			{
				if (isHit(shot, ships2) and hasShips(ships2))
				{ continue; }

				turnPlayer1 = false;
			}
			else
			{
				if (isHit(shot, ships1) and hasShips(ships1))
				{ continue; }

				turnPlayer1 = true;
			}

			// If the game is over, break out of the loop.
			if (not hasShips(ships1) or not hasShips(ships2))
			{
				if ((not hasShips(ships2)) and (not turnPlayer1))
				{ continue; }

				break;
			}
		}

		// Print the result.
		if (hasShips(ships1) and not hasShips(ships2))
		{ cout << "player one wins\n"; }
		else if (hasShips(ships2) and not hasShips(ships1))
		{ cout << "player two wins\n"; }
		else
		{ cout << "draw\n"; }
	}
}

/*
 * Lessons learned:
 * Do not try to be too clever...
 *
 * "Debugging is twice as hard as writing the code in the first place.
 * Therefore, if you write the code as cleverly as possible, you are,
 * by definition, not smart enough to debug it."
 * - Brian Kernighan
 */
