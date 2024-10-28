//
//	981. Time Based Key-Value Store
//	leetcode.com/problems/time-based-key-value-store/
//
//  Created by Danial Haseeb on 18/10/2024.
//


class TimeMap
{
	var map: [String: [(value: String, timestamp: Int)]] = [:]

	func set(_ key: String, _ value: String, _ timestamp: Int)
	{ map[key, default: []].append((value, timestamp)) }

	func get(_ key: String, _ timestamp: Int) -> String
	{
		var value = ""

		guard let values = map[key] else
		{ return value }

		var (left, right) = (0, values.count - 1)

		while left <= right
		{
			let mid = left + (right - left) / 2

			if values[mid].timestamp < timestamp
			{
				value = values[mid].value
				left = mid + 1
			}
			else if values[mid].timestamp > timestamp
			{ right = mid - 1 }
			else
			{ return values[mid].value }
		}

		return value
	}
}
