/**
 * Calculating Dart Scores
 * @see https://open.kattis.com/problems/calculatingdartscores
 *
 * @author Danial Haseeb
 *
 * Helper file to precalculate the dart scores.
 */

#include <iostream>
#include <utility>

using namespace std;

auto print(const int multiplier, const int score)
{
	switch (multiplier)
	{
		case 1:
			cout << "single ";
			break;
		case 2:
			cout << "double ";
			break;
		case 3:
			cout << "triple ";
			break;
		default:
			return;
	}

	cout << score << "\\n";
}

auto main() -> int
{
	bool found{};

	for (auto target{ 1 }; target <= 180; ++target)
	{
		for (auto score1{ 1 }; score1 <= 20; ++score1)
		{
			for (int multiplier1{}; multiplier1 <= 3; ++multiplier1)
			{
				for (auto score2{ 1 }; score2 <= 20; ++score2)
				{
					for (int multiplier2{}; multiplier2 <= 3; ++multiplier2)
					{
						for (auto score3{ 1 }; score3 <= 20; ++score3)
						{
							for (int multiplier3{}; multiplier3 <= 3; ++multiplier3)
							{
								const auto firstScore = score1 * multiplier1;
								const auto secondScore = score2 * multiplier2;
								const auto thirdScore = score3 * multiplier3;

								if (firstScore + secondScore + thirdScore == target)
								{
									found = true;
									cout << '"';
									print(multiplier1, score1);
									print(multiplier2, score2);
									print(multiplier3, score3);
									cout << "\",\n";
									goto nextTarget;
								}
							}
						}
					}
				}
			}
		}
		nextTarget:
			if (not found)
			{ cout << "\"impossible\\n\",\n"; }

			found = false;
	}

	return 0;
}
