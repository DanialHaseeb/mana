//
// 278. First Bad Version
// https://leetcode.com/problems/first-bad-version
//
// Created by Danial Haseeb on 07/11/2023.
//

class Solution: VersionControl
{
	func firstBadVersion(_ n: Int) -> Int
	{
		var (high, low) = (n, 1)

		while low < high
		{
			let mid = low + ((high - low) / 2)

			if isBadVersion(mid)
			{ high = mid }
			else
			{ low = mid + 1 }
		}

		return low
	}
}
