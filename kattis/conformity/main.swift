//
//  Conformity
//  https://open.kattis.com/problems/conformity
//
//  Created by Danial Haseeb on 08/10/2023.
//

let n = Int(readLine()!)!

var popularities: [[Int]: Int] = [:]

for _ in 0..<n
{
	let line = readLine()!
		.split(separator: " ")
		.map { Int($0)! }
		.sorted()

	popularities[line, default: 0] += 1
}

var mostPopular = 0
for (_, popularity) in popularities
{ mostPopular = max(mostPopular, popularity) }

var students = 0
for (_, popularity) in popularities
{ students += ((popularity == mostPopular) ? popularity : 0) }

print(students)
