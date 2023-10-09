//
//  Count the Vowels
//  https://open.kattis.com/problems/countthevowels
//
//  Created by Danial Haseeb on 08/10/2023.
//

extension Character
{
	var isVowel: Bool
	{ return "aeiouAEIOU".contains(self) }
}

let s = readLine()!

var vowels = 0

for character in s
{
	if character.isVowel
	{ vowels += 1 }
}

print(vowels)
