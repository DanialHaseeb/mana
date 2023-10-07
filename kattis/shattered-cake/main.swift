//
//  Shattered Cake
//  https://open.kattis.com/problems/shatteredcake
//
//  Created by Danial Haseeb on 04/10/2023.
//

let w = Int(readLine()!)!

let n = Int(readLine()!)!

var area = 0

for _ in (1...n)
{
	let input = readLine()!
		.split(separator: " ")
		.map { Int($0)! }

	let (width, length) = (input[0], input[1])

	area += width * length
}

print(area / w)
