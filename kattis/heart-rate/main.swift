//
//  Heart Rate
//  https://open.kattis.com/problems/heartrate
//
//  Created by Danial Haseeb on 03/10/2023.
//

let n = Int(readLine()!)!

for _ in (1...n)
{
	let input = readLine()!
		.split(separator: " ")
		.map { Double($0)! }

	let (b, p) = (input[0], input[1])

	let bpm = 60 * b / p
	let δ = 60 / p

	print(bpm - δ, bpm, bpm + δ)
}
