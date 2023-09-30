//
//  Oddities
//  https://open.kattis.com/problems/oddities
//
//  Created by Danial Haseeb on 30/09/2023.
//

let n = Int(readLine()!)!

for _ in (0..<n)
{
	let x = Int(readLine()!)!
	print("\(x) is \(x % 2 == 0 ? "even" : "odd")")
}
