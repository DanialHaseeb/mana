//
//  Fruit Baskets
//  https://open.kattis.com/problems/fruitbaskets
//
//  Created by Danial Haseeb on 29/09/2023.
//

let n = Int(readLine()!)!

let subsets = 1 << n

var total = 0
var fruits = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

for fruit in fruits
{ total += fruit * subsets / 2 }

for i in (0..<n)
{
	let total1 = fruits[i]
	
	if total1 < 200
	{ total -= total1 }
	
	for j in (i+1..<n)
	{
		let total2 = fruits[j] + total1
		
		if total2 < 200
		{ total -= total2 }
		
		for k in (j+1..<n)
		{
			let total3 = fruits[k] + total2
			
			if total3 < 200
			{ total -= total3 }
		}
	}
}

print(total)
