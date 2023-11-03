//
//  What Does It Mean?
//  https://open.kattis.com/problems/heritage
//
//  Created by Danial Haseeb on 25/10/2023.
//

let modulus = 1_000_000_007

func meanings(of w: String,
							in dictionary: [Character: [String: Int]],
							i: Int,
							_ memo: inout [Int: Int])
-> Int
{
	let n = w.count - 1
	guard (i <= n) else
	{ return 1 }

	if let memoised = memo[i]
	{ return memoised }

	let index = w.index(w.startIndex, offsetBy: i)
	let current = w[index]
	var meanings = 0

	if let d = dictionary[current]
	{
		for (part, k) in d
		{
			if w[index...].hasPrefix(part)
			{
				let offset = i + part.count
				meanings = (meanings + k * meanings(of: w, in: dictionary, i: offset, &memo)) % modulus
			}
		}
	}

	memo[i] = meanings
	return meanings
}

let input = readLine()!.split(separator: " ")
let (n, w) = (Int(input[0])!, String(input[1]))

var dictionary: [Character: [String: Int]] = [:]

for _ in (1...n)
{
	let line = readLine()!.split(separator: " ")
	let a = String(line[0])
	let b = Int(line[1])!

	if dictionary[a.first!] == nil
	{ dictionary[a.first!] = [:] }

	dictionary[a.first!]?[a] = b
}

var memo: [Int: Int] = [:]
print(meanings(of: w, in: dictionary, i: 0, &memo))
