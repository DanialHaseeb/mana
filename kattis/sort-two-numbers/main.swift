//
//  Sort Two Numbers
//  https://open.kattis.com/problems/sorttwonumbers
//
//  Created by Danial Haseeb on 08/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (a, b) = (input[0], input[1])

let smaller = min(a, b)
let bigger = max(a, b)

print(smaller, bigger)
