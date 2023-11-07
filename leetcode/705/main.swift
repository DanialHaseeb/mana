//
//  705. Design HashSet
//  https://leetcode.com/problems/design-hashset
//
//  Created by Danial Haseeb on 04/11/2023.
//

class MyHashSet
{
	struct List
	{
		class Node
		{
			let key: Int
			var next: Node?

			init(_ key: Int)
			{ self.key = key }
		}

		var head: Node?

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

		mutating func add(_ key: Int)
		{
			guard !contains(key) else
			{ return }

			let node = Node(key)
			node.next = head
			head = node
		}

		mutating func remove(_ key: Int)
		{
			guard head != nil else
			{ return }

			guard head!.key != key else
			{
				head = head!.next
				return
			}

			var node = head
			while node!.next != nil
			{
				if node!.next!.key == key
				{
					node!.next = node!.next!.next
					return
				}

				node = node!.next
			}
		}
	}

	static let size = 10_000

	let hash = { $0 % size }
	var array = Array(repeating: List(), count: size)

	func add(_ key: Int)
	{
		let index = hash(key)
		array[index].add(key)
	}

	func remove(_ key: Int)
	{
		let index = hash(key)
		array[index].remove(key)
	}

	func contains(_ key: Int) -> Bool
	{
		let index = hash(key)
		return array[index].contains(key)
	}
}
