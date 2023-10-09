//
//  Cryptographer's Conundrum
//  https://open.kattis.com/problems/conundrum
//
//  Created by Danial Haseeb on 09/10/2023.
//

let cipher = readLine()!

var counter = 0

for i in stride(from: 0, to: cipher.count, by: 3)
{
	let index1 = cipher.index(cipher.startIndex, offsetBy: i)
	let index2 = cipher.index(cipher.startIndex, offsetBy: i + 1)
	let index3 = cipher.index(cipher.startIndex, offsetBy: i + 2)

	if cipher[index1] != "P"
	{ counter += 1 }

	if cipher[index2] != "E"
	{ counter += 1 }

	if cipher[index3] != "R"
	{ counter += 1 }
}

print(counter)
