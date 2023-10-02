//
//  Cetvrta
//  https://open.kattis.com/problems/cetvrta
//
//  Created by Danial Haseeb on 2/10/2023.
//

var input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (x1, y1) = (input[0], input[1])

input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (x2, y2) = (input[0], input[1])

input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (x3, y3) = (input[0], input[1])

var x4: Int
{
	if x1 == x2
	{ return x3 }
	else if x1 == x3
	{ return x2 }
	else
	{ return x1 }
}

var y4: Int
{
	if y1 == y2
	{ return y3 }
	else if y1 == y3
	{ return y2 }
	else
	{ return y1 }
}

print("\(x4) \(y4)")
