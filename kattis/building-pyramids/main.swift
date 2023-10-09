//
//  Building Pyramids
//  https://open.kattis.com/problems/pyramids
//
//  Created by Danial Haseeb on 09/10/2023.
//

let n = Int(readLine()!)!

var height = 0

var blocks = 0
var side = 1
while blocks < n
{
	blocks += side * side
	side += 2
	height += 1
}

if blocks > n
{ height -= 1 }

print(height)
