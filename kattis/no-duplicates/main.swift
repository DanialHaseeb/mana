//
//  No Duplicates
//  https://open.kattis.com/problems/nodup
//
//  Created by Danial Haseeb on 09/10/2023.
//

import Foundation

let words = readLine()!
	.split(separator: " ")

for (i, word) in words.enumerated()
{
	if words[i+1..<words.count].contains(word)
	{
		print("no")
		exit(0)
	}
}

print("yes")
