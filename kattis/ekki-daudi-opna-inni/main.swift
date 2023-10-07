//
//  Ekki dauði opna inni
//  https://open.kattis.com/problems/ekkidaudi
//
//  Created by Danial Haseeb on 04/10/2023.
//

var first = ""
var second = ""

while let input = readLine()?.split(separator: "|").map({ String($0) })
{
	first.append((input[0]))
	second.append(input[1])
}

print(first, second)
