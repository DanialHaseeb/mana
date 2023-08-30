#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
	public:
		auto bestClosingTime(string customers) -> int
		{
			/// The total numbers of hours where customes come.
			const auto totalY{ count(customers.cbegin(), customers.cend(), 'Y') };

			/// The total numbers of hours where no customes come.
			const auto totalX{ count(customers.cbegin(), customers.cend(), 'N') };

			vector<int> penalties(customers.length() + 1);

			/// The number of hours so far where customers come.
			auto currentY{ 0 };

			/// The number of hours so far where no customers come.
			auto currentX{ 0 };

			for (size_t i{}; i < customers.length(); ++i)
			{
				/// The number of hours where customers come after the current hour.
				const auto futureY{ totalY - currentY };

				/// The penalty for closing at the current hour.
				const auto penalty{ currentX + futureY };

				penalties[i] = penalty;

				(customers[i] == 'Y') ? ++currentY : ++currentX;
			}

			/// The penalty for closing at the last hour.
			penalties[customers.length()] = currentX;

			/// The best penalty.
			const auto bestPenalty{ min_element(penalties.cbegin(), penalties.cend()) };

			/// The best hour to close.
			const auto bestHour{ find(penalties.cbegin(), penalties.cend(), *bestPenalty) };

			return distance(penalties.cbegin(), bestHour);
		}
};
