//
//  An I for an Eye
//  https://open.kattis.com/problems/iforaneye
//
//  Created by Danial Haseeb on 29/09/2023.
//

extension String
{
	mutating func abbreviated(using abbreviations: [Character: [String]])
	{
		var index = self.startIndex

		while index < self.endIndex
		{
			var longest = -1
			var replacement: Character?

			for (abbreviation, sequences) in abbreviations
			{
				for sequence in sequences
				{
					let endIndex = self
						.index(index, offsetBy: sequence.count, limitedBy: self.endIndex)

					if let
						endIndex,
						self[index..<endIndex].lowercased() == sequence.lowercased()
					{
						if sequence.count > longest
						{
							longest = sequence.count
							replacement = abbreviation

							if self[index].isUppercase
							{ replacement = Character(replacement!.uppercased()) }
						}
					}
				}
			}

			if let replacement
			{
				let range = index..<self.index(index, offsetBy: longest)
				self.replaceSubrange(range, with: String(replacement))
				index = self.index(index, offsetBy: 1)
			}
			else
			{ index = self.index(index, offsetBy: 1) }
		}
	}
}

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
	print(line.abbreviated(using: abbreviations))
}
