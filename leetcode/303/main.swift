//
// 303. Range Sum Query - Immutable
// https://leetcode.com/problems/range-sum-query-immutable
//
//  Created by Danial Haseeb on 04/11/2023.
//


class NumArray
{
	let sums: [Int]

	init(_ nums: [Int])
	{
		var sums = Array(repeating: 0, count: nums.count)

		var sum = 0
		for (i, number) in nums.enumerated()
		{
			sum += number
			sums[i] = sum
		}

		self.sums = sums
	}

	func sumRange(_ left: Int, _ right: Int) -> Int
	{
		let leftSum = (left == 0) ? 0 : sums[left - 1]
		let rightSum = sums[right]

		return rightSum - leftSum
	}
}
