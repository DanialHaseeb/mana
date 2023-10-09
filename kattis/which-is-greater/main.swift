//
//  Which is Greater?
//  https://open.kattis.com/problems/whichisgreater
//
//  Created by Danial Haseeb on 08/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (a, b) = (input[0], input[1])

print((a > b) ? "1" : "0")
