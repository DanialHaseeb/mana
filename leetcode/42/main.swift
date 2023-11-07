//
// 42. Trapping Rain Water
// https://leetcode.com/problems/trapping-rain-water
//
// Created by Danial Haseeb on 07/11/2023.
//

class Solution
{
	func trap(_ height: [Int]) -> Int
	{
		guard !height.isEmpty else
		{ return 0 }

		var (left, right) = (0, height.count - 1)
		var (leftMax, rightMax) = (height[left], height[right])
		var result = 0

		while left < right
		{
			if leftMax < rightMax
			{
				left += 1
				leftMax = max(leftMax, height[left])
				result += leftMax - height[left]
			}
			else
			{
				right -= 1
				rightMax = max(rightMax, height[right])
				result += rightMax - height[right]
			}
		}

		return result
	}
}
