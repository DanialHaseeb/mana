//
//  Studentsko
//  https://open.kattis.com/problems/studentsko
//
//  Created by Danial Haseeb on 25/10/2023.
//

extension Array where Element: Comparable
{
	/// Returns the index where the given element should be inserted in an array.
	func insertionIndex(of value: Element) -> Int
	{
		var low = 0
		var high = count

		while low < high
		{
			let mid = (low + high) / 2
			if self[mid] <= value
			{ low = mid + 1 }
			else
			{ high = mid }
		}

		return low
	}
}

let inputs = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (n, k) = (inputs[0], inputs[1])

let skills = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

// Determine the desired team position for each student based on their skill.
var desiredTeamForSkill: [Int: Int] = [:]
let sortedSkills = skills.sorted()
for (i, skill) in sortedSkills.enumerated()
{ desiredTeamForSkill[skill] = i / k }

// Transform the original skill list to represent desired teams.
let desiredTeams = skills.map { desiredTeamForSkill[$0]! }

// Calculate the Longest Increasing Subsequence.
var lis: [Int] = []
for team in desiredTeams
{
	let position = lis.insertionIndex(of: team)
	if position == lis.count
	{ lis.append(team) }
	else
	{ lis[position] = team }
}

// Output the number of students that need to be rearranged.
print(desiredTeams.count - lis.count)
