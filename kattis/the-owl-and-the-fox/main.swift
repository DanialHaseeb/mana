//
//  The Owl and the Fox
//  https://open.kattis.com/problems/owlandfox
//
//  Created by Danial Haseeb on 30/09/2023.
//

extension Int
{
	var digitSum: Int
	{
		var n = self
		var result = 0
		while n > 0
		{
			result += n % 10
			n /= 10
		}
		return result
	}
}

let t = Int(readLine()!)!

for _ in (0..<t)
{
	let n = Int(readLine()!)!
	
	for i in (0..<n).reversed()
	{
		if i.digitSum == (n.digitSum - 1)
		{
			print(i)
			break
		}
	}
}
