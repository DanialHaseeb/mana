//
//  Alphabet Spam
//  https://open.kattis.com/problems/alphabetspam
//
//  Created by Danial Haseeb on 09/10/2023.
//

let string = readLine()!

let length = Double(string.count)

var whitespace = 0
var lowercase = 0
var uppercase = 0
var symbols = 0

for character in string
{
	if character == "_"
	{ whitespace += 1 }
	else if character.isLowercase
	{ lowercase += 1 }
	else if character.isUppercase
	{ uppercase += 1 }
	else
	{ symbols += 1 }
}

print(Double(whitespace) / length)
print(Double(lowercase) / length)
print(Double(uppercase) / length)
print(Double(symbols) / length)
