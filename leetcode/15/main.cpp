#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
		auto threeSum(vector<int>& nums) -> vector<vector<int>>
		{
			vector<vector<int>> results;

			sort(nums.begin(), nums.end());

			const auto n{ nums.size() };

			for (size_t i{}; i < (n - 2); ++i)
			{
				// Skip duplicates for nums[i].
				if ((i > 0) and (nums[i] == nums[i - 1]))
				{ continue; }

				const auto a{ nums[i] };
				auto start{ i + 1 };
				auto end{ n - 1 };

				while (start < end)
				{
					const auto b{ nums[start] };
					const auto c{ nums[end] };

					const auto sum{ a + b + c };

					if (sum == 0)
					{
						results.push_back({ a, b, c });

						// Skip duplicates for nums[start].
						while ((start < end) and (nums[start] == nums[start + 1]))
						{ ++start; }

						// Skip duplicates for nums[end].
						while ((start < end) and (nums[end] == nums[end - 1]))
						{ --end; }

						++start;
						--end;
					}
					else if (sum < 0)
					{ ++start; }
					else
					{ --end; }
				}
			}

			return results;
		}
};
