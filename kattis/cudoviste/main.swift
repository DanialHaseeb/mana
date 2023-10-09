//
//  Cudoviste
//  https://open.kattis.com/problems/cudoviste
//
//  Created by Danial Haseeb on 09/10/2023.
//

let input = readLine()!.split(separator: " ").map { Int($0)! }
let (r, c) = (input[0], input[1])

// Read the map into a 2D array.
var grid: [[Character]] = []

for _ in (1...r)
{
	let row = Array(readLine()!)
	grid.append(row)
}

var counts = [0, 0, 0, 0, 0]

for i in (0..<(r-1))
{
	for j in (0..<(c-1))
	{
		var carsCount = 0

		let subGrid: [[Character]] =
		[
			[grid[i][j], grid[i][j+1]],
			[grid[i+1][j], grid[i+1][j+1]]
		]

		// Count squished cars.
		for row in subGrid
		{
			for cell in row where cell == "X"
			{ carsCount += 1 }
		}

		// Check for buildings.
		var buildingPresent = false
		for row in subGrid
		{
			for cell in row where cell == "#"
			{
				buildingPresent = true
				break
			}
		}

		// If there are no buildings, update the counts.
		if !buildingPresent
		{ counts[carsCount] += 1 }
	}
}

// Print the results.
for count in counts
{ print(count) }
