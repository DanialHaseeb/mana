//
// 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku
//
// Created by Danial Haseeb on 06/11/2023.
//

class Solution
{
	let n = 9
	let boxIndices =
	[
		[0, 0, 0, 1, 1, 1, 2, 2, 2],
		[0, 0, 0, 1, 1, 1, 2, 2, 2],
		[0, 0, 0, 1, 1, 1, 2, 2, 2],
		[3, 3, 3, 4, 4, 4, 5, 5, 5],
		[3, 3, 3, 4, 4, 4, 5, 5, 5],
		[3, 3, 3, 4, 4, 4, 5, 5, 5],
		[6, 6, 6, 7, 7, 7, 8, 8, 8],
		[6, 6, 6, 7, 7, 7, 8, 8, 8],
		[6, 6, 6, 7, 7, 7, 8, 8, 8]
	]

	func isValidSudoku(_ board: [[Character]]) -> Bool
	{
		var rows: [Set<Character>] = Array(repeating: [], count: n)
		var columns: [Set<Character>] = Array(repeating: [], count: n)
		var boxes: [Set<Character>] = Array(repeating: [], count: n)

		for (i, row) in board.enumerated()
		{
			for (j, cell) in row.enumerated()
			{
				if cell == "."
				{ continue }

				let boxIndex = boxIndices[i][j]

				if rows[i].contains(cell) ||
					 columns[j].contains(cell) ||
					 boxes[boxIndex].contains(cell)
				{ return false }

				rows[i].insert(cell)
				columns[j].insert(cell)
				boxes[boxIndex].insert(cell)
			}
		}

		return true
	}
}
