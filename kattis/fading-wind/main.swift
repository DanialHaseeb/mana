//
//  Fading Wind
//  https://open.kattis.com/problems/fadingwind
//
//  Created by Danial Haseeb on 09/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

var (h, k, v, s) = (input[0], input[1], input[2], input[3])

var distance = 0

while h > 0
{
	v += s
	v -= max(1,  v / 10)

	if v >= k
	{ h += 1 }

	if (v > 0) && (v < k)
	{
		h -= 1

		if h == 0
		{ v = 0 }
	}

	if v <= 0
	{
		h = 0
		v = 0
	}

	distance += v

	if s > 0
	{ s -= 1 }
}

print(distance)
