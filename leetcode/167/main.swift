//
// 167. Two Sum II - Input Array Is Sorted
// https://leetcode.com/problems/two-sum-ii-input-array-is-sorted
//
// Created by Danial Haseeb on 06/11/2023.
//

class Solution
{
	func twoSum(_ numbers: [Int], _ target: Int) -> [Int]
	{
		var (left, right) = (0, numbers.count-1)

		while left < right
		{
			let sum = numbers[left] + numbers[right]

			guard sum != target else
			{ return [left+1, right+1] }

			if sum < target
			{ left += 1 }
			else
			{ right -= 1 }
		}

		return []
	}
}
