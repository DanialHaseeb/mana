//
// 11. Container With Most Water
// https://leetcode.com/problems/container-with-most-water
//
// Created by Danial Haseeb on 07/11/2023.
//

class Solution
{
	func maxArea(_ height: [Int]) -> Int
	{
		var (left, right) = (0, height.count-1)

		var result = 0

		while left < right
		{
			let (leftHeight, rightHeight) = (height[left], height[right])
			let area = min(leftHeight, rightHeight) * (right - left)
			result = max(result, area)

			if leftHeight < rightHeight
			{ left += 1 }
			else
			{ right -= 1 }
		}

		return result
	}
}
