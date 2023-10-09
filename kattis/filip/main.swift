//
//  Filip
//  https://open.kattis.com/problems/filip
//
//  Created by Danial Haseeb on 09/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { $0.reversed() }
	.map { Int(String($0))! }

let (a, b) = (input[0], input[1])

let bigger = max(a, b)

print(bigger)
