//
// 206. Reverse Linked List
// https://leetcode.com/problems/reverse-linked-list
//
// Created by Danial Haseeb on 05/02/2024.
//

class Solution
{
	func reverseList(_ head: ListNode?) -> ListNode?
	{
		var previous: ListNode? = nil
		var current = head
		while current != nil
		{
			let next = current?.next
			current?.next = previous
			previous = current
			current = next
		}
		return previous
	}
}
