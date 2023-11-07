//
// 724. Find Pivot Index
// https://leetcode.com/problems/find-pivot-index
//
//  Created by Danial Haseeb on 04/11/2023.
//

class Solution
{
	func pivotIndex(_ nums: [Int]) -> Int
	{
		let sum = nums.reduce(0, +)

		var leftSum = 0

		for (i, number) in nums.enumerated()
		{
			let rightSum = sum - leftSum - number

			if leftSum == rightSum
			{ return i }

			leftSum += number
		}

		return -1
	}
}
