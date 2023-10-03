//
//  Alice in the Digital World
//  https://open.kattis.com/problems/addingtrouble
//
//  Created by Danial Haseeb on 03/10/2023.
//

let datasets = Int(readLine()!)!

for _ in (1...datasets)
{
	let input = readLine()!
		.split(separator: " ")
		.map { Int($0)! }

	let (n, m) = (input[0], input[1])

	let dataset = readLine()!
		.split(separator: " ")
		.map { Int($0)! }

	var best = Int()
	var sum = Int()
	var i = Int()
	var minI = Int()
	var hasMin = Bool()

	while i < n
	{
		let datum = dataset[i]

		if datum < m
		{
			sum = 0
			hasMin = false
			i += 1
			continue
		}

		if datum == m
		{
			if hasMin
			{
				hasMin = false
				i = minI + 1
				sum = 0
				continue
			}
			else
			{
				hasMin = true
				minI = i
			}
		}

		sum += datum

		if hasMin
		{ best = max(sum, best) }

		i += 1
	}

	print(best)
}
