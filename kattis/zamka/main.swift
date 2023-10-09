//
//  Zamka
//  https://open.kattis.com/problems/zamka
//
//  Created by Danial Haseeb on 08/10/2023.
//

let (l, d, x) = (Int(readLine()!)!, Int(readLine()!)!, Int(readLine()!)!)

var minimum = Int.max
var maximum = Int.min

for i in (l...d)
{
	var sum = 0

	var j = i
	while j != 0
	{
		sum += j % 10
		j /= 10
	}

	if sum == x
	{
		minimum = min(minimum, i)
		maximum = max(maximum, i)
	}
}

print(minimum)
print(maximum)
