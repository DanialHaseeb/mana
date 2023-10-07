//
//  300. Longest Increasing Subsequences
//  https://leetcode.com/problems/longest-increasing-subsequence/
//
//  Created by Danial Haseeb on 04/10/2023.
//

class Solution
{
	func lengthOfLIS(_ nums: [Int]) -> Int
	{
		let n = nums.count
		var dp = Array<Int>(repeating: 1, count: n)

		for i in (1..<n)
		{
			for j in (0..<i).reversed()
			{
				if (nums[j] < nums[i]) && (dp[j] + 1 > dp[i])
				{ dp[i] = dp[j] + 1 }
			}
		}

		return dp.max()!
	}
}
