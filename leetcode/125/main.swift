//
// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome
//
// Created by Danial Haseeb on 06/11/2023.
//

class Solution
{
	func isPalindrome(_ s: String) -> Bool
	{
		let s = Array(s.lowercased().filter { $0.isLetter || $0.isNumber })
		let n = s.count

		var i = 0
		var j = n - 1

		while i < j
		{
			if s[i] != s[j]
			{ return false }

			i += 1
			j -= 1
		}

		return true
	}
}
