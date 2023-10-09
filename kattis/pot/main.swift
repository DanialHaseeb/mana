//
//  Pot
//  https://open.kattis.com/problems/pot
//
//  Created by Danial Haseeb on 09/10/2023.
//

import Foundation

let n = Int(readLine()!)!

var total = 0

for _ in (1...n)
{
	let x = Int(readLine()!)!

	let power = x % 10
	let number = x / 10

	total += Int(pow(Double(number), Double(power)))
}

print(total)
