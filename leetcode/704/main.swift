//
// 704. Binary Search
// https://leetcode.com/problems/binary-search
//
// Created by Danial Haseeb on 07/11/2023.
//

class Solution
{
	func search(_ nums: [Int], _ target: Int) -> Int
	{
		var left = 0
		var right = nums.count - 1

		while left <= right
		{
			let mid = (left) + ((right - left) / 2)

			guard (nums[mid] != target) else
			{ return mid }

			if nums[mid] < target
			{ left = mid + 1 }
			else
			{ right = mid - 1 }
		}

		return -1
	}
}
