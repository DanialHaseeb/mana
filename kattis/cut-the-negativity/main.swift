//
//  Last Factorial Digit
//  https://open.kattis.com/problems/lastfactorialdigit
//
//  Created by Danial Haseeb on 08/10/2023.
//

// Read the size of the array.
let n = Int(readLine()!)!

// Read the 2D array.
var costs: [[Int]] = Array(repeating: Array(repeating: 0, count: n), count: n)
for i in (0..<n)
{
	let cost = readLine()!
		.split(separator: " ")
		.map { Int($0)! }

	costs[i] = cost
}

// Find the positive values and their positions.
var m: [(Int, Int, Int)] = []
for i in (0..<n)
{
	for j in (0..<n )
	{
		let c = costs[i][j]
		if c > 0
		{
			let u = i + 1
			let v = j + 1
			m.append((u, v, c))
		}
	}
}

// Print the results.
print(m.count)
for (u, v, c) in m
{ print(u, v, c) }
