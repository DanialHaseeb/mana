//
// 304. Range Sum Query 2D - Immutable
// https://leetcode.com/problems/range-sum-query-2d-immutable
//
//  Created by Danial Haseeb on 04/11/2023.
//

class NumMatrix
{
	let sums: [[Int]]

	init(_ matrix: [[Int]])
	{
		let (m, n) = (matrix.count, matrix[0].count)

		var sums = Array(repeating: Array(repeating: 0, count: n+1), count: m+1)

		for r in (0..<m)
		{
			var prefixSum = 0
			for c in (0..<n)
			{
				prefixSum += matrix[r][c]
				let sumAbove =  sums[r][c + 1]
				sums[r+1][c+1] = prefixSum + sumAbove
			}
		}

		self.sums = sums
	}

	func sumRegion(_ row1: Int, _ col1: Int, _ row2: Int, _ col2: Int) -> Int
	{
		let bottomRight = sums[row2+1][col2+1]
		let above = sums[row1][col2+1]
		let left = sums[row2+1][col1]
		let topLeft = sums[row1][col1]

		return bottomRight - above - left + topLeft
	}
}
