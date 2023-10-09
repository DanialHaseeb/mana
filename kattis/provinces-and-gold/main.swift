//
//  Provinces and Gold
//  https://open.kattis.com/problems/provincesandgold
//
//  Created by Danial Haseeb on 09/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (g, s, c) = (input[0], input[1], input[2])

let sum = 3*g + 2*s + 1*c

if sum >= 2
{
	if sum >= 8
	{ print("Province", terminator: "") }
	else if sum >= 5
	{ print("Duchy", terminator: "") }
	else
	{ print("Estate", terminator: "") }

	print(" or ", terminator: "")
}

if sum >= 6
{ print("Gold") }
else if sum >= 3
{ print("Silver") }
else
{ print("Copper") }
