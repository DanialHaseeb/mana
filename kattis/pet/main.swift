//
//  Pet
//  https://open.kattis.com/problems/pet
//
//  Created by Danial Haseeb on 09/10/2023.
//

let n = 5

var scores: [Int] = Array(repeating: 0, count: n)

for i in (0..<n)
{
	let score = readLine()!
		.split(separator: " ")
		.map { Int($0)! }
		.reduce(0, +)

	scores[i] = score
}

let maxScore = scores.max()!
let winner = scores.firstIndex(of: maxScore)! + 1

print(winner, maxScore)
