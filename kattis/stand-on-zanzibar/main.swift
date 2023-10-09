//
//  Stand on Zanzibar
//  https://open.kattis.com/problems/zanzibar
//
//  Created by Danial Haseeb on 09/10/2023.
//

let t = Int(readLine()!)!

for _ in (1...t)
{
	var totalImportedTurtles = 0
	var currentCount = 1

	let inputValues = readLine()!
		.split(separator: " ")
		.map { Int($0)! }

	for nextCount in inputValues
	{
		let doubledCount = currentCount * 2

		if doubledCount < nextCount
		{ totalImportedTurtles += nextCount - doubledCount }

		currentCount = nextCount
	}

	print(totalImportedTurtles)
}
