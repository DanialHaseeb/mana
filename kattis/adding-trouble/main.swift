//
//  Adding Trouble
//  https://open.kattis.com/problems/addingtrouble
//
//  Created by Danial Haseeb on 30/09/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (a, b, c) = (input[0], input[1], input[2])

print((a + b == c) ? "correct!" : "wrong!")
