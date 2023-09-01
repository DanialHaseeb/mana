#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		auto fourSum(vector<int>& nums, int target) -> vector<vector<int>>
		{
			vector<vector<int>> results;

			if (nums.size() < 4)
			{ return results; }

			sort(nums.begin(), nums.end());

			const auto n = nums.size();

			for (size_t i{}; i < (n - 3); ++i)
			{
				// Skip duplicates for i.
				if ((i > 0) and (nums[i] == nums[i-1]))
				{ continue; }

				for (auto j{ i + 1 }; j < (n - 2); ++j)
				{
					// Skip duplicates for j.
					if ((j > (i + 1)) and (nums[j] == nums[j-1]))
					{ continue; }

					auto start{ j + 1 };
					auto end{ n - 1 };

					while (start < end)
					{
						long long a{ nums[i] };
						long long b{ nums[j] };
						long long c{ nums[start] };
						long long d{ nums[end] };

						long long sum{ a + b + c + d };

						if (sum == target)
						{
							results.push_back
							({
								static_cast<int>(a),
								static_cast<int>(b),
								static_cast<int>(c),
								static_cast<int>(d)
							});

							// Skip duplicates for start and end
							while ((start < end) and (nums[start] == nums[start + 1]))
							{ ++start; }

							while ((start < end) and (nums[end] == nums[end - 1]))
							{ --end; }

							++start;
							--end;
						}
						else if (sum < target)
						{ ++start; }
						else
						{ --end; }
					}
				}
			}
			return results;
		}
};
