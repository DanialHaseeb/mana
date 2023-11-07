//
// 560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k
//
// Created by Danial Haseeb on 05/11/2023.
//

class Solution
{
	func subarraySum(_ nums: [Int], _ k: Int) -> Int
	{
		var result = 0

		var sum = 0
		var sumCounts = [sum: 1]

		for number in nums
		{
			sum += number

			if let count = sumCounts[sum - k]
			{ result += count }

			sumCounts[sum, default: 0] += 1
		}

		return result
	}
}
