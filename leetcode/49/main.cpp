#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
	public:
		auto groupAnagrams(vector<string>& strs) -> vector<vector<string>>
		{
			unordered_map<string, vector<string>> map;

			for (const auto& str : strs)
			{
				string sorted{ str };
				sort(sorted.begin(), sorted.end());
				map[sorted].push_back(str);
			}

			vector<vector<string>> result;

			for (const auto& [str, anagrams] : map)
			{ result.push_back(anagrams); }

			return result;
		}
};
