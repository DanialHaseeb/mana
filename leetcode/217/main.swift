//
//  217. Contains Duplicates
//  https://leetcode.com/problems/contains-duplicate/
//
//  Created by Danial Haseeb on 03/11/2023.
//

class Solution
{
	func containsDuplicate(_ nums: [Int]) -> Bool
	{
		var set: Set<Int> = []

		for number in nums
		{
			if set.contains(number)
			{ return true }

			set.insert(number)
		}
		return false
	}
}
