//
//  646. Maximum Length of Pair Chain
//  https://leetcode.com/problems/maximum-length-of-pair-chain/
//
//  Created by Danial Haseeb on 04/10/2023.
//

class Solution
{
	func findLongestChain(_ pairs: [[Int]]) -> Int
	{
		var pairs = pairs
		pairs.sort { $0[1] < $1[1] }

		var result = 1

		var lastLink = pairs[0][1]

		for pair in pairs
		{
			if lastLink < pair[0]
			{
				lastLink = pair[1]
				result += 1
			}
		}

		return result
	}
}
