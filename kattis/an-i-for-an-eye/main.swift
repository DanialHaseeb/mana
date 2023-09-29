//
//  An I for an Eye
//  https://open.kattis.com/problems/iforaneye
//
//  Created by Danial Haseeb on 29/09/2023.
//

let abbreviations: [Character: [String]] =
[
	"@": ["at"],
	"&": ["and"],
	"1": ["one", "won"],
	"2": ["to", "too", "two"],
	"4": ["for", "four"],
	"b": ["bea", "be", "bee"],
	"c": ["sea", "see"],
	"i": ["eye"],
	"o": ["oh", "owe"],
	"r": ["are"],
	"u": ["you"],
	"y": ["why"]
]

let n = Int(readLine()!)!

for _ in 0..<n
{
	var line = readLine()!
	abbreviate(&line, using: abbreviations)
	print(line)
}

func abbreviate(_ line: inout String, using abbreviations: [Character: [String]])
{
	var index = line.startIndex

	while index < line.endIndex
	{
		var longest = -1
		var replacement: Character?

		for (abbreviation, sequences) in abbreviations
		{
			for sequence in sequences
			{
				let endIndex = line
					.index(index, offsetBy: sequence.count, limitedBy: line.endIndex)

				if let
					endIndex,
					line[index..<endIndex].lowercased() == sequence.lowercased()
				{
					if sequence.count > longest
					{
						longest = sequence.count
						replacement = abbreviation

						if line[index].isUppercase
						{ replacement = Character(replacement!.uppercased()) }
					}
				}
			}
		}

		if let replacement
		{
			let range = index..<line.index(index, offsetBy: longest)
			line.replaceSubrange(range, with: String(replacement))
			index = line.index(index, offsetBy: 1)
		}
		else
		{ index = line.index(index, offsetBy: 1) }
	}
}
