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


	var best = 0
	var current = 0

	var mIndex = 0
	var hasMin = false


	var i = 0

	while i < n
	{
		let datum = dataset[i]

		if datum < m
		{
			current = 0
			hasMin = false
			i += 1
			continue
		}

		if datum == m
		{
			if hasMin
			{
				hasMin = false
				i = mIndex + 1
				current = 0
				continue
			}
			else
			{
				hasMin = true
				mIndex = i
			}
		}

		current += datum

		if hasMin
		{ best = max(current, best) }

		i += 1
	}

	print(best)
}
