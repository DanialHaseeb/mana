//
//	33. Search in Rotated Sorted Array
//	https://leetcode.com/problems/search-in-rotated-sorted-array
//
//  Created by Danial Haseeb on 03/12/2023.
//

class Solution
{
	func search(_ nums: [Int], _ target: Int) -> Int
	{
		var (left, right) = (0, nums.count - 1)

		while left <= right
		{
			let mid = left + (right - left) / 2

			if nums[mid] == target
			{ return mid }

			if nums[mid] >= nums[left]
			{
				if target >= nums[left] && target < nums[mid]
				{ right = mid - 1 }
				else
				{ left = mid + 1 }
			}
			else
			{
				if target <= nums[right] && target > nums[mid]
				{ left = mid + 1 }
				else
				{ right = mid - 1 }
			}
		}

		return -1
	}
}
