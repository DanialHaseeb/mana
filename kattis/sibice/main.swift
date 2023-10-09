//
//  Sibice
//  https://open.kattis.com/problems/sibice
//
//  Created by Danial Haseeb on 09/10/2023.
//

import Foundation

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (n, w, h) = (input[0], input[1], input[2])

let maxLength = Int(sqrt(Double(w * w + h * h)))

for _ in (0..<n)
{
	let length = Int(readLine()!)!

	print(length <= maxLength ? "DA" : "NE")
}
