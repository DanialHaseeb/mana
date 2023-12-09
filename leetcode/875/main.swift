//
//	875. Koko Eating Bananas
//	https://leetcode.com/problems/koko-eating-bananas
//
//  Created by Danial Haseeb on 03/12/2023.
//

import Foundation

class Solution
{
	func minEatingSpeed(_ piles: [Int], _ h: Int) -> Int
	{
		var (left, right) = (1, piles.max()!)

		var result = right

		while (left <= right)
		{
			let mid = left + (right - left) / 2

			var hours = 0

			for pile in piles
			{ hours += Int(ceil(Double(pile) / Double(mid))) }

			let bananasLeft = (hours > h)

			if bananasLeft
			{ left = mid + 1 }
			else
			{
				right = mid - 1
				result = min(result, mid)
			}
		}

		return result
	}
}
