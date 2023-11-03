//
//  Narrow Art Gallery
//  https://open.kattis.com/problems/narrowartgallery
//
//  Created by Danial Haseeb on 26/10/2023.
//

typealias Gallery = [[Int]]

extension Gallery
{
	init(size n: Int)
	{
		var result: Gallery = []
		for _ in (1...n)
		{ result.append(readLine()!.split(separator: " ").map { Int($0)! }) }
		self.init(result)
	}
}


func value(of gallery: Gallery, withRoomsClosed k: Int) -> Int
{
	guard (k > 0) else
	{ return gallery.reduce(0) { $0 + $1[0] + $1[1] } }

	let n = gallery.count

	var dp: [[[Int]]] =
		Array(repeating: Array(repeating: Array(repeating: -1, count: 3), count: k + 1),
					count: n)

	dp[0][0][0] = gallery[0].reduce(0, +)
	dp[0][1][1] = gallery[0][1]
	dp[0][1][2] = gallery[0][0]

	for i in (1..<n)
	{
		for j in (0...min(i+1, k))
		{
			var maximum = dp[i-1][j].max()!
			if maximum > -1
			{ dp[i][j][0] = gallery[i][0] + gallery[i][1] + maximum }

			if j > 0
			{
				maximum = max(dp[i-1][j-1][0], dp[i-1][j-1][1])
				if maximum > -1
				{ dp[i][j][1] = gallery[i][1] + maximum }

				maximum = max(dp[i-1][j-1][0], dp[i-1][j-1][2])
				if maximum > -1
				{ dp[i][j][2] = gallery[i][0] + maximum }
			}
		}
	}

	return dp[n-1][k].max()!
}


while true
{
	let input = readLine()!
		.split(separator: " ")
		.map { Int($0)! }

	let (n, k) = (input[0], input[1])

	guard (n, k) != (0, 0) else
	{ break }

	let gallery = Gallery(size: n)
	print(value(of: gallery, withRoomsClosed: k))
}
