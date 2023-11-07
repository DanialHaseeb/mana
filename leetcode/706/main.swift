//
//  706. Design HashMap
//  https://leetcode.com/problems/design-hashmap
//
//  Created by Danial Haseeb on 04/11/2023.
//

class MyHashMap
{
	struct List
	{
		class Node
		{
			let key: Int
			var value: Int
			var next: Node?

			init(key: Int, value: Int)
			{
				self.key = key
				self.value = value
			}
		}

		var head: Node?

		var isEmpty: Bool
		{ head == nil }

		func contains(_ key: Int) -> Bool
		{
			var node = head
			while node != nil
			{
				if node!.key == key
				{ return true }
				node = node!.next
			}
			return false
		}

		mutating func add(_ node: Node)
		{
			guard !isEmpty else
			{
				head = node
				return
			}

			var current = head

			while current!.next != nil
			{
				guard current!.key != node.key else
				{
					current!.value = node.value
					return
				}

				current = current!.next
			}

			if current!.key == node.key
			{ current!.value = node.value }
			else
			{ current!.next = node }
		}

		mutating func remove(_ key: Int)
		{
			guard !isEmpty else
			{ return }

			guard head!.key != key else
			{
				head = head!.next
				return
			}

			var current = head
			while current!.next != nil
			{
				if current!.next!.key == key
				{
					current!.next = current!.next!.next
					return
				}
				current = current!.next
			}
		}
	}

	static let size = 10_000

	let hash = { $0 % size }
	var array = Array(repeating: List(), count: size)

	func put(_ key: Int, _ value: Int)
	{
		let node = List.Node(key: key, value: value)
		array[hash(key)].add(node)
	}

	func get(_ key: Int) -> Int
	{
		let list = array[hash(key)]

		var node = list.head

		while node != nil
		{
			if node!.key == key
			{ return node!.value }

			node = node!.next
		}

		return -1
	}

	func remove(_ key: Int)
	{ array[hash(key)].remove(key) }
}
