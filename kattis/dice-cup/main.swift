//
//  Dice Cup
//  https://open.kattis.com/problems/dicecup
//
//  Created by Danial Haseeb on 09/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (n, m) = (input[0], input[1])

if n == m
{ print(n + 1) }
else
{
	let start = min(n, m) + 1
	let outcomes = abs(n - m) + 1
	let end = start + outcomes
	for i in (start..<end)
	{ print(i) }
}
