//
// 80. Remove Duplicates from Sorted Array II
// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii
//
// Created by Danial Haseeb on 07/11/2023.
//

class Solution
{
	func removeDuplicates(_ nums: inout [Int]) -> Int
	{
		let n = nums.count
		var (left, right) = (0, 0)

		while right < n
		{
			var count = 1

			while (right+1 < n) && (nums[right] == nums[right + 1])
			{
				right += 1
				count += 1
			}

			for _ in (0..<(min(2, count)))
			{
				nums[left] = nums[right]
				left += 1
			}

			right += 1
		}

		return left
	}
}
