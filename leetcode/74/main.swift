//
// 74. Search a 2D Matrix
// https://leetcode.com/problems/search-a-2d-matrix
//
// Created by Danial Haseeb on 07/11/2023.
//

class Solution
{
	func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool
	{
		let (m, n) = (matrix.count, matrix[0].count)

		var (top, bottom) = (0, m-1)

		while top <= bottom
		{
			let mid = top + (bottom - top) / 2

			let (left, right) = (matrix[mid].first!, matrix[mid].last!)

			guard !((left...right).contains(target)) else
			{ break }

			if target < left
			{ bottom = mid - 1 }
			else
			{ top = mid + 1 }
		}

		guard (top <= bottom) else
		{ return false }

		let row = top + (bottom - top) / 2

		var (left, right) = (0, n-1)

		while left <= right
		{
			let mid = left + (right - left) / 2

			guard target != matrix[row][mid] else
			{ return true }

			if target > matrix[row][mid]
			{ left = mid + 1 }
			else
			{ right = mid - 1 }
		}

		return false
	}
}
