//
//  Avion
//  https://open.kattis.com/problems/avion
//
//  Created by Danial Haseeb on 09/10/2023.
//

var gotAway = true

for i in (1...5)
{
	let code = readLine()!

	if code.contains("FBI")
	{
		gotAway = false
		print(i, terminator: " ")
	}
}

if gotAway
{ print("HE GOT AWAY!") }
