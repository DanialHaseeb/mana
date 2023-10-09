//
//  Last Factorial Digit
//  https://open.kattis.com/problems/lastfactorialdigit
//
//  Created by Danial Haseeb on 08/10/2023.
//

extension Int
{
	var factorial: Int
	{
		if self == 0
		{ return 1 }
		else
		{ return self * (self - 1).factorial }
	}

	var lastDigit: Int
	{ return self % 10 }
}

let t = Int(readLine()!)!

for _ in 0..<t
{
	let n = Int(readLine()!)!
	print(n.factorial.lastDigit)
}
