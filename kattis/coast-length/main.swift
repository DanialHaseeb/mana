//
//  Coast Length
//  https://open.kattis.com/problems/coast
//
// 	Created by Danial Haseeb on 05/12/2023.
//

print(coastLength(of: input()))

class Square: CustomStringConvertible
{
	enum Value
	{
		case water
		case land
	}

	let value: Value
	var isVisited = false

	init(_ value: Value)
	{ self.value = value }

	var description: String
	{
		switch value
		{
			case .water: return "W"
			case .land: return "L"
		}
	}
}

typealias Grid = [[Square]]

extension Grid
{
	func padded(with value: Square.Value) -> Grid
	{
		let m = self[0].count

		let firstRow = (1...m+2).map { _ in Square(value) }
		let paddedColumns = self.map { [Square(value)] + $0 + [Square(value)] }
		let lastRow = (1...m+2).map { _ in Square(value) }

		return [firstRow] + paddedColumns + [lastRow]
	}

	func neighbors(of row: Int, _ column: Int) -> [(Int, Int)]
	{
		var result: [(Int, Int)] = []

		if row > 0
		{ result.append((row-1, column)) }

		if row < self.count - 1
		{ result.append((row+1, column)) }

		if column > 0
		{ result.append((row, column-1)) }

		if column < self[0].count - 1
		{ result.append((row, column+1)) }

		return result
	}
}

func coastLength(of map: Grid) -> Int
{
	let map = map.padded(with: .water)

	var length = 0

	var frontier = [(0, 0)]

	while !(frontier.isEmpty)
	{
		let (row, column) = frontier.removeLast()
		let square = map[row][column]

		if square.isVisited
		{ continue }
		else
		{ square.isVisited = true }

		for neighbour in map.neighbors(of: row, column)
		{
			let (row, column) = neighbour
			let square = map[row][column]

			switch square.value
			{
				case .land:  length += 1
				case .water: frontier.append(neighbour)
			}
		}
	}

	return length
}

func input() -> Grid
{
	let n = readLine()!
		.split(separator: " ")
		.compactMap { Int($0) }
		.first!

	let map = (1...n).map
	{(_) in
		readLine()!.map
		{ ($0 == "0") ? Square(.water) : Square(.land) }
	}

	return map
}
