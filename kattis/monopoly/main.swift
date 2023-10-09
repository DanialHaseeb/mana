//
//  Monopoly
//  https://open.kattis.com/problems/monopol
//
//  Created by Danial Haseeb on 09/10/2023.
//

// Read the number of hotels and the distances.
let _ = readLine()!

let distances = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

// Probabilities of each possible sum when rolling two 6-sided dice.
let probabilities =
[
	 2:  1.0 / 36.0,
	 3:  2.0 / 36.0,
	 4:  3.0 / 36.0,
	 5:  4.0 / 36.0,
	 6:  5.0 / 36.0,
	 7:  6.0 / 36.0,
	 8:  5.0 / 36.0,
	 9:  4.0 / 36.0,
	10:  3.0 / 36.0,
	11:  2.0 / 36.0,
	12:  1.0 / 36.0
]

var totalProbability = 0.0

for distance in distances
{ totalProbability += probabilities[distance] ?? 0.0 }

print(totalProbability)
