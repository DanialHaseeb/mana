//
//  Chanukah Challenge
//  https://open.kattis.com/problems/chanukah
//
//  Created by Danial Haseeb on 30/09/2023.
//

let p = Int(readLine()!)!

for _ in (0..<p )
{
	let input = readLine()!.split(separator: " ").map { Int($0)! }
	let (k, n) = (input[0], input[1])
	let candles = n * (n + 1) / 2 + n
	print("\(k) \(candles)")
}
