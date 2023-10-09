//
//  Two-sum
//  https://open.kattis.com/problems/twosum
//
//  Created by Danial Haseeb on 08/10/2023.
//

let sum = readLine()!
	.split(separator: " ")
	.map { Int($0)! }
	.reduce(0, +)

print(sum)
