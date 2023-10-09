//
//  Reversed Binary Numbers
//  https://open.kattis.com/problems/reversebinary
//
//  Created by Danial Haseeb on 09/10/2023.
//

let n = Int(readLine()!)!
let binary = String(n, radix: 2)
let reversedBinary = binary.reversed()
let result = Int(String(reversedBinary), radix: 2)!
print(result)
