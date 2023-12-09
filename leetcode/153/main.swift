//
//	153. Find Minimum in Rotated Sorted Array
//	https://leetcode.com/problems/find-minimum-in-rotated-sorted-array
//
//  Created by Danial Haseeb on 03/12/2023.
//

class Solution
{
	func findMin(_ nums: [Int]) -> Int
	{
		var result = nums.first!

		var (left, right) = (0, nums.count - 1)

		while left <= right
		{
			if nums[left] <= nums[right]
			{
				result = min(result, nums[left])
				break
			}

			let mid = left + (right - left) / 2

			result = min(result, nums[mid])

			if nums[mid] >= nums[left]
			{
				left = mid + 1
			}
			else
			{
				right = mid - 1
			}
		}

		return result
	}
}
