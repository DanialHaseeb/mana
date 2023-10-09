//
//  Modulo
//  https://open.kattis.com/problems/modulo
//
//  Created by Danial Haseeb on 09/10/2023.
//

var values: Set<Int> = []

for _ in (1...10)
{ values.insert(Int(readLine()!)! % 42) }

print(values.count)
