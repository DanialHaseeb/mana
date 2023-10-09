//
//  Piece of Cake
//  https://open.kattis.com/problems/pieceofcake2
//
//  Created by Danial Haseeb on 08/10/2023.
//

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (n, h, v) = (input[0], input[1], input[2])

let volume = 4 * max(h, n - h) * max(v, n - v)

print(volume)
