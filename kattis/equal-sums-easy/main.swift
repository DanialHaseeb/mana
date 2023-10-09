//
//  Equal Sums (Easy)
//  https://open.kattis.com/problems/equalsumseasy
//
//  Created by Danial Haseeb on 17/10/2023.
//

let t = Int(readLine()!)!

for test in (1...t)
{
	var integers = readLine()!
		.split(separator: " ")
		.map { Int($0)! }

	let n = integers.removeFirst()

	print("Case #\(test):")

	var sums: [Int: [Int]] = [:]

	for i in (1..<(1 << n))
	{
		let subset = integers.enumerated()
			.filter { (1 << $0.offset) & i != 0 }
			.map { $0.element }

		let sum = subset.reduce(0, +)

		sums[sum, default: []].append(i)
	}

	for (_, subsets) in sums
	{
		if subsets.count < 2
		{ continue }

		let subset1 = integers.enumerated()
			.filter { (1 << $0.offset) & subsets[0] != 0 }
			.map { $0.element }

		let subset2 = integers.enumerated()
			.filter { (1 << $0.offset) & subsets[1] != 0 }
			.map { $0.element }

		print(subset1.map { String($0) }.joined(separator: " "))
		print(subset2.map { String($0) }.joined(separator: " "))

		break
	}
}
