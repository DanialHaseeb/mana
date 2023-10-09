//
//  Spavanac
//  https://open.kattis.com/problems/spavanac
//
//  Created by Danial Haseeb on 08/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

var (h, m) = (input[0], input[1])

m += 15;

if m / 60 == 0
{ h -= 1 }
else
{ m %= 60 }

if(h < 0)
{ h += 24 }

print("\(h) \(m)")
