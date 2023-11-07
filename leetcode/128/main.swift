//
// 128. Longest Consecutive Sequence
// https://leetcode.com/problems/longest-consecutive-sequence
//
// Created by Danial Haseeb on 06/11/2023.
//

class Solution
{
	func longestConsecutive(_ nums: [Int]) -> Int
	{
		let set = Set(nums)

		var result = 0

		for number in nums
		{
			var length = 1
			let previous = number - 1

			guard !set.contains(previous) else
			{ continue }

			var next = number + 1

			while set.contains(next)
			{
				length += 1
				next += 1
			}

			result = max(result, length)
		}

		return result
	}
}
