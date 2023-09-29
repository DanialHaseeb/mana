//
//  Room Painting
//  https://open.kattis.com/problems/roompainting
//
//  Created by Danial Haseeb on 29/09/2023.
//

var input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (n, m) = (input[0], input[1])

var cans: [Int] = []
for _ in (0..<n)
{ cans.append(Int(readLine()!)!) }

cans.sort()

var wasted = 0

for _ in (0..<m)
{
	let need = Int(readLine()!)!
	
	for can in cans
	{
		if can >= need
		{
			wasted += (can - need)
			break
		}
	}
}

print(wasted)
