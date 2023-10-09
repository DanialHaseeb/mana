//
//  Number Fun
//  https://open.kattis.com/problems/numberfun
//
//  Created by Danial Haseeb on 09/10/2023.
//

let n = Int(readLine()!)!

for _ in (1...n)
{
	let numbers = readLine()!
		.split(separator: " ")
		.map { Int($0)! }

	let (a, b, c) = (numbers[0], numbers[1], numbers[2])

	if a + b == c
	{ print("Possible") }
	else if abs(a - b) == c
	{ print("Possible") }
	else if a * b == c
	{ print("Possible") }
	else if (a % b == 0 && a / b == c) || (b % a == 0 && b / a == c)
	{ print("Possible") }
	else
	{ print("Impossible") }
}
