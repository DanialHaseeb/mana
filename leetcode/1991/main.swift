//
// 1991. Find the Middle Index in Array
// https://leetcode.com/problems/find-the-middle-index-in-array
//
//  Created by Danial Haseeb on 04/11/2023.
//

class Solution
{
	func findMiddleIndex(_ nums: [Int]) -> Int
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
