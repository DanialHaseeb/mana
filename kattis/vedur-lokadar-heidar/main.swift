//
//  Veður - Lokaðar heiðar
//  https://open.kattis.com/problems/vedurheidar
//
//  Created by Danial Haseeb on 09/10/2023.
//

let v = Int(readLine()!)!
let n = Int(readLine()!)!

for _ in (0..<n )
{
	let input = readLine()!
		.split(separator: " ")

	let (r, k) = (input[0], Int(input[1])!)

	print("\(r) \(k < v ? "lokud" : "opin")")
}
