//
//  I've Been Everywhere, Man
//  https://open.kattis.com/problems/everywhere
//
//  Created by Danial Haseeb on 30/09/2023.
//

let t = Int(readLine()!)!

for _ in (0..<t)
{
	let n = Int(readLine()!)!
	var cities = Set<String>()
	for _ in (0..<n)
	{ cities.insert(readLine()!) }
	print(cities.count)
}
