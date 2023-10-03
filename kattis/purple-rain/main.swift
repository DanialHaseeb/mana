//
//  Purple Rain
//  https://open.kattis.com/problems/purplerain
//
//  Created by Danial Haseeb on 03/10/2023.
//

let rain = readLine()!

var (blue, red, purple) = (0, 0, 0)
var (blueStart, redStart) = (1, 1)
var (start, end) = (0, 0)

var i = 0

for drop in rain
{
	i += 1

	if drop == "R"
	{
		red += 1
		blue -= 1
	}
	else
	{
		blue += 1
		red -= 1
	}

	if blue < 0
	{
		blueStart = i + 1
		blue = 0
	}

	if red < 0
	{
		redStart = i + 1
		red = 0
	}

	if red > purple
	{
		purple = red
		start = redStart
		end = i
	}

	if blue > purple
	{
		purple = blue
		start = blueStart
		end = i
	}
}

print(start, end)
