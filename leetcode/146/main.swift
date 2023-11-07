//
//  146. LRU Cache
//  https://leetcode.com/problems/lru-cache
//
//  Created by Danial Haseeb on 03/11/2023.
//

class LRUCache
{
	typealias Key = Int
	typealias Value = Int

	class List
	{
		class Node
		{
			var key: Key
			var value: Value
			var next: Node?
			var previous: Node?

			init(key: Key, value: Value)
			{
				self.key = key
				self.value = value
			}
		}

		var head: Node?
		var tail: Node?

		var isEmpty: Bool
		{ head == nil }

		func append(_ node: Node)
		{
			guard !isEmpty else
			{
				head = node
				tail = node
				return
			}

			tail!.next = node
			node.previous = tail
			tail = node
		}

		func remove(_ node: Node)
		{
			guard !isEmpty else { return }

			guard node !== head else
			{
				head = node.next
				head?.previous = nil
				return
			}

			guard node !== tail else
			{
				tail = node.previous
				tail?.next = nil
				return
			}

			node.previous?.next = node.next
			node.next?.previous = node.previous
		}
	}

	let capacity: Int
	var dictionary: [Key: List.Node] = [:]
	var list = List()

	init(_ capacity: Int)
	{ self.capacity = capacity }

	func get(_ key: Int) -> Int
	{
		if let node = dictionary[key]
		{
			list.remove(node)
			list.append(node)
			return node.value
		}
		else
		{ return -1 }
	}

	func put(_ key: Int, _ value: Int)
	{
		if let node = dictionary[key]
		{
			node.value = value
			list.remove(node)
			list.append(node)
		}
		else
		{
			let node = List.Node(key: key, value: value)
			dictionary[key] = node
			list.append(node)

			if dictionary.count > capacity
			{
				dictionary.removeValue(forKey: list.head!.key)
				list.remove(list.head!)
			}
		}
	}
}
