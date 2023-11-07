//
//  242. Valid Anagram
//  https://leetcode.com/problems/valid-anagram/
//
//  Created by Danial Haseeb on 03/11/2023.
//

class Solution
{
	func isAnagram(_ s: String, _ t: String) -> Bool
	{
		if s.count != t.count
		{ return false }

		var sDictionary: [Character: Int] = [:]
		var tDictionary: [Character: Int] = [:]

		for character in s
		{ sDictionary[character, default: 0] += 1 }

		for character in t
		{ tDictionary[character, default: 0] += 1 }

		return sDictionary == tDictionary
	}
}
