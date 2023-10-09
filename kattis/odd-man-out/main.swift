//
//  Odd Man Out
//  https://open.kattis.com/problems/oddmanout
//
//  Created by Danial Haseeb on 09/10/2023.
//

// Read number of test cases.
let n = Int(readLine()!)!

for x in (1...n)
{
	/// /Number of guests (not used).
	_ = Int(readLine()!)

	// Read the invitation codes.
	let codes = readLine()!
		.split(separator: " ")
		.map { Int($0)! }

	var odds: [Int: Int] = [:]

	// Count occurrences of each code.
	for code in codes
	{ odds[code, default: 0] += 1 }

	// Find and print the code that appears once.
	for (c, value) in odds
	{
		if value == 1
		{
			print("Case #\(x): \(c)")
			break
		}
	}
}
