//
// 26. Remove Duplicates from Sorted Array
// https://leetcode.com/problems/remove-duplicates-from-sorted-array
//
// Created by Danial Haseeb on 07/11/2023.
//

class Solution
{
	func removeDuplicates(_ nums: inout [Int]) -> Int
	{
		var unique = 1

		for (i, number) in nums.enumerated()
		{
			guard i != 0 else
			{ continue }

			let isUnique = number != nums[i - 1]
			if isUnique
			{
				nums[unique] = number
				unique += 1
			}
		}

		return unique
	}
}
