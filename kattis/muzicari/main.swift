//
//  Muzicari
//  https://open.kattis.com/problems/muzicari
//
//  Created by Danial Haseeb on 25/10/2023.
//

func canFitBreak(of index: Int,
								 withTimeLeft1 remainingTime1: Int,
								 andTimeLeft2 remainingTime2: Int,
								 _ breaks: [Int] = breaks,
								 _ dp: inout [[Int: Bool]])
-> Bool
{
	if index == breaks.count
	{ return (remainingTime1 >= 0) && (remainingTime2 >= 0) }

	if let cached = dp[index][remainingTime1]
	{ return cached }

	// Try to put the current break into the first group.
	let tryFirstGroup = canFitBreak(of: index+1,
																	withTimeLeft1: remainingTime1 - breaks[index],
																	andTimeLeft2: remainingTime2,
																	breaks,
																	&dp)

	// Try to put the current break into the second group.
	let trySecondGroup = canFitBreak(of: index+1,
																	 withTimeLeft1: remainingTime1,
																	 andTimeLeft2: remainingTime2 - breaks[index],
																	 breaks,
																	 &dp)

	dp[index][remainingTime1] = tryFirstGroup || trySecondGroup

	return dp[index][remainingTime1]!
}

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (t, n) = (input[0], input[1])

let breaks = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

var dp: [[Int: Bool]] = Array(repeating: [:], count: n)
var results = Array(repeating: 0, count: n)

var (t1, t2) = (t, t)

for i in (0..<n)
{
	let musician = i + 1
	let remainingTime1 = t1 - breaks[i]
	if canFitBreak(of: musician, withTimeLeft1: remainingTime1, andTimeLeft2: t2, breaks, &dp)
	{
		results[i] = t - t1
		t1 -= breaks[i]
	}
	else
	{
		results[i] = t - t2
		t2 -= breaks[i]
	}
}

print(results.map(String.init).joined(separator: " "))
