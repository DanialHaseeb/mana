//
//  Kornislav
//  https://open.kattis.com/problems/kornislav
//
//  Created by Danial Haseeb on 09/10/2023.
//

let inputs = readLine()!
	.split(separator: " ")
	.map { Int($0)! }
	.sorted()

print(inputs[0] * inputs[2])
