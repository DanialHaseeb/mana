//
//  Hanging Out on the Terrace
//  https://open.kattis.com/problems/hangingout
//
//  Created by Danial Haseeb on 09/10/2023.
//

// Read the fire safety limit and the number of events.
let input = readLine()!
	.split(separator: " ")
	.map({ Int($0)! })

let (l, x) = (input[0], input[1])

var (currentCount, deniedGroups) = (0, 0)

for _ in (0..<x)
{
		let event = readLine()!
			.split(separator: " ")
			.map({ String($0) })

		let description = event[0]
		let p = Int(event[1])!

		if description == "enter"
		{
			if currentCount + p > l
			{ deniedGroups += 1 }
			else
			{ currentCount += p }
		}
		else
		{ currentCount -= p }
}

// Print the number of groups that were denied access
print(deniedGroups)
