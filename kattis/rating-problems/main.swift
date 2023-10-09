//
//  Rating Problems
//  https://open.kattis.com/problems/ratingproblems
//
//  Created by Danial Haseeb on 08/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (n, k) = (input[0], input[1])

var r = Array<Int>(repeating: 0, count: k)

for i in 0..<k
{ r[i] = Int(readLine()!)! }

let current = r.reduce(0, +)

let remaining  = n - k
let minimum = current - 3 * remaining
let maximum = current + 3 * remaining

print(Double(minimum) / Double(n), Double(maximum) / Double(n))
