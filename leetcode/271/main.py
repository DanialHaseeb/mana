"""
LeetCode

271. Encode and Decode Strings
:see: https://leetcode.com/problems/encode-and-decode-strings/

:author: Danial Haseeb
"""

class Solution:
	def encode(self, strs: list[str]) -> str:
		result = ""
		for string in strs:
			result += f"{len(string)}:{string}"
		return result

	def decode(self, str: str) -> list[str]:
		result: list["str"] = []
		i = 0
		while i < len(str):
			encoded_length = ""
			while str[i] != ":":
				encoded_length += str[i]
				i += 1
			length = int(encoded_length)
			i += 1
			result.append(str[i:i+length])
			i += length
		return result
