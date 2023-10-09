//
//  Vefþjónatjón
//  https://open.kattis.com/problems/vefthjonatjon
//
//  Created by Danial Haseeb on 09/10/2023.
//

let n = Int(readLine()!)!

var cpus: [Character] = []
cpus.reserveCapacity(n)

var memories: [Character] = []
memories.reserveCapacity(n)

var harddrives: [Character] = []
harddrives.reserveCapacity(n)

for _ in (0..<n )
{
	let letters = readLine()!
		.split(separator: " ")
		.map { Character(String($0)) }

	cpus.append(letters[0])
	memories.append(letters[1])
	harddrives.append(letters[2])
}

func isJ(_ c: Character) -> Bool
{ return c == "J" }

let servers = min(cpus.filter(isJ).count,
                  memories.filter(isJ).count,
                  harddrives.filter(isJ).count)

print(servers)
