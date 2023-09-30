//
//  Spritt
//  https://open.kattis.com/problems/spritt
//
//  Created by Danial Haseeb on 30/09/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (n, x) = (input[0], input[1])

var total = 0

for _ in (0..<n)
{ total += Int(readLine()!)! }

print((total <= x) ? "Jebb" : "Neibb")
