//
//  Nasty Hacks
//  https://open.kattis.com/problems/nastyhacks
//
//  Created by Danial Haseeb on 2/10/2023.
//

let n = Int(readLine()!)!

for _ in (1...n)
{
	let input = readLine()!
		.split(separator: " ")
		.map { Int($0)! }

	let (r, e, c) = (input[0], input[1], input[2])

	if r < e - c
	{ print("advertise") }
	else if r == e - c
	{ print("does not matter") }
	else
	{ print("do not advertise") }
}
