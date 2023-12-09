//
// 374. Guess Number Higher or Lower
// https://leetcode.com/problems/guess-number-higher-or-lower
//
// Created by Danial Haseeb on 07/11/2023.
//

class Solution: GuessGame
{
	func guessNumber(_ n: Int) -> Int
	{
		var low = 1
		var high = n

		while low <= high
		{
			let mid = low + ((high - low) / 2)

			let result = guess(mid)

			guard result != 0 else
			{ return mid }

			if result == -1
			{ high = mid - 1 }
			else
			{ low = mid + 1 }
		}

		return -1
	}
}
