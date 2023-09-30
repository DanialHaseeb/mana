//
//  Gradutaion
//  https://open.kattis.com/problems/skolavslutningen
//
//  Created by Danial Haseeb on 30/09/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (n, m, k) = (input[0], input[1], input[2])

var lineup: [[Character]] =
	Array(repeating: Array(repeating: "A", count: n), count: m)

for i in (0..<n)
{
	let input = readLine()!
	for (j, className) in input.enumerated()
	{ lineup[j][i] = className }
}

var columns: [Set<Character>] = []

for column in lineup
{
	var classes: Set<Character> = []
	
	for className in column
	{ classes.insert(className) }
	
	columns.append(classes)
}

var colours = 0

for i in (0..<m)
{
	var unique = true
	
	for j in (0..<i)
	{ unique = unique && columns[i].intersection(columns[j]).isEmpty }
	
	if unique
	{ colours += 1 }
}

print(colours)
