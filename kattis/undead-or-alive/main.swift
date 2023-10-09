//
//  Undead or Alive
//  https://open.kattis.com/problems/undeadoralive
//
//  Created by Danial Haseeb on 08/10/2023.
//

let line = readLine()!

if line.contains(":)") && !line.contains(":(")
{ print("alive") }
else if !line.contains(":)") && line.contains(":(")
{ print("undead") }
else if line.contains(":)") && line.contains(":(")
{ print("double agent") }
else
{ print("machine") }
