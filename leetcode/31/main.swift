class Solution
{
	func nextPermutation(_ nums: inout [Int])
	{
		var k: Int?

		// Find the largest index k such that a[k] < a[k + 1].
		for i in (0..<nums.count - 1).reversed()
		{
			if nums[i] < nums[i + 1]
			{
				k = i
				break
			}
		}

		// If no such index exists, the permutation is the last permutation.
		guard (k != nil) else
		{
			nums.reverse()
			return
		}

		// Find the largest index l greater than k such that a[k] < a[l].
		var l = k! + 1

		for i in (k! + 2..<nums.count)
		{
			if nums[k!] < nums[i]
			{ l = i }
		}

		// Swap the value of a[k] with that of a[l].
		nums.swapAt(k!, l)

		// Reverse the sequence from a[k + 1] up to and including the final element a[n].
		nums[(k! + 1)...].reverse()
	}
}
