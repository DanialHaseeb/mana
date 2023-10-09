//
//  Seven Wonders
//  https://open.kattis.com/problems/sevenwonders
//
//  Created by Danial Haseeb on 09/10/2023.
//

let cards = readLine()!

var (t, c, g) = (0, 0, 0)

for card in cards
{
	switch card
	{
		case "T": t += 1
		case "C": c += 1
		case "G": g += 1

		default: break
	}
}

let points = (min(min(t, c), g) * 7) + ((t*t)+(c*c)+(g*g))

print(points)
