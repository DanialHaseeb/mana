//
//  Open Source
//  https://open.kattis.com/problems/opensource
//
//  Created by Danial Haseeb on 25/10/2023.
//

var students = [String: String]()
var projects = [String: Set<String>]()
var current: String?

while let line = readLine()
{
	if line == "0"
	{ break	}
	else if line == "1"
	{
		let sortedProjects = projects.sorted
		{
			if $0.value.count == $1.value.count
			{ return $0.key < $1.key }
			return $0.value.count > $1.value.count
		}

		for (projectName, studentSet) in sortedProjects
		{ print("\(projectName) \(studentSet.count)") }

		students.removeAll()
		projects.removeAll()
	}
	else if line.first!.isUppercase
	{
		current = line.trimmingCharacters(in: .newlines)
		projects[current!] = Set<String>()
	}
	else
	{
		let student = line.trimmingCharacters(in: .newlines)
		if let studentProject = students[student], studentProject != current
		{
			if studentProject != "#"
			{ projects[studentProject]?.remove(student) }
			students[student] = "#"
		}
		else
		{
			if let currentProject = current
			{
				projects[currentProject, default: Set<String>()].insert(student)
				students[student] = currentProject
			}
		}
	}
}
