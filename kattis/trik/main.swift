//
//  Trik
//  https://open.kattis.com/problems/trik
//
//  Created by Danial Haseeb on 06/10/2023.
//

let moves = readLine()!

var ball = 1

for move in moves
{
	switch move
	{
		case "A":
			if ball == 1
			{ ball = 2 }
			else if ball == 2
			{ ball = 1 }
		case "B":
			if ball == 2
			{ ball = 3 }
			else if ball == 3
			{ ball = 2 }
		case "C":
			if ball == 1
			{ ball = 3 }
			else if ball == 3
			{ ball = 1 }
		default:
			break
	}
}

print(ball)
