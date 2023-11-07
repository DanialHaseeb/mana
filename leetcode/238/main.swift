//
// 238. Product of Array Except Self
// https://leetcode.com/problems/product-of-array-except-self
//
// Created by Danial Haseeb on 04/11/2023.
//

class Solution
{
	func productExceptSelf(_ nums: [Int]) -> [Int]
	{
		let n = nums.count

		var prefixProducts = Array(repeating: 1, count: n)

		for (i, number) in nums.enumerated()
		{ prefixProducts[i] = ((i > 0) ? prefixProducts[i - 1] : 1) * number }

		var suffixProducts = Array(repeating: 1, count: n)

		for (i, number) in nums.reversed().enumerated()
		{ suffixProducts[i] = ((i > 0) ? suffixProducts[i - 1] : 1) * number }

		var result = Array(repeating: 1, count: n)

		for i in (0..<n)
		{
			let prefix = (i > 0) ? prefixProducts[i - 1] : 1
			let suffix = (i < n - 1) ? suffixProducts[n - i - 2] : 1

			result[i] = prefix * suffix
		}

		return result
	}
}
