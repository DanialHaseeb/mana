//
//  GCVWR
//  https://open.kattis.com/problems/gcvwr
//
//  Created by Danial Haseeb on 08/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (g, t, n) = (input[0], input[1], input[2])

let w = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let remaining = g - t
let limit = remaining * 9 / 10
let sum = w.reduce(0, +)

print(limit - sum)
