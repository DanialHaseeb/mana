//
//  347. Top K Frequent Elements
//  https://leetcode.com/problems/top-k-frequent-elements/
//
//  Created by Danial Haseeb on 03/11/2023.
//

class Solution
{
	func topKFrequent(_ nums: [Int], _ k: Int) -> [Int]
	{

		var dictionary: [Int: Int] = [:]

		for number in nums
		{ dictionary[number, default: 0] += 1 }

		var result: [Int] = []
		for _ in 1...k
		{ result.append(popMode(&dictionary)) }

		return result
	}

	func popMode(_ dictionary: inout [Int: Int]) -> Int
	{
		var mode: Int = 0
		var maxFrequency: Int = 0

		for (number, frequency) in dictionary
		{
			if frequency > maxFrequency
			{
				mode = number
				maxFrequency = frequency
			}
		}

		dictionary.removeValue(forKey: mode)

		return mode
	}
}
