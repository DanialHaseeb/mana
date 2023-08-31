#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		auto twoSum(vector<int>& nums, int target) -> vector<int>
		{
			unordered_map<int, size_t> map;
			vector<int> result(2);

			for (size_t i{}; i < nums.size(); ++i)
			{
				const auto complement{ target - nums[i] };

				if (map.find(complement) != map.end())
				{
					result[0] = static_cast<int>(map[complement]);
					result[1] = static_cast<int>(i);
				}
				else
				{ map[nums[i]] = i; }
			}

			return result;
		}
};
