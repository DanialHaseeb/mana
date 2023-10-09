//
//  Triangle Area
//  https://open.kattis.com/problems/triarea
//
//  Created by Danial Haseeb on 08/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Double($0)! }

let (b, h) = (input[0], input[1])

print(b * h / 2.0)
