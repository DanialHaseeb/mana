//
//  Build Dependencies
//  https://open.kattis.com/problems/builddeps
//
// 	Created by Danial Haseeb on 06/12/2023.
//

import Foundation

let (graph, file) = input()
compileSequence(of: file, in: graph).forEach { print($0) }

typealias File = String
typealias Graph = [File: [File]]

func input() -> (Graph, File)
{
	let n = Int(readLine()!)!

	var graph = Graph()

	for _ in (1...n)
	{
		let inputs = readLine()!
			.split(separator: ":")
			.map(String.init)

		let file = inputs.first!

		if (graph[file] == nil)
		{ graph[file] = [] }

		guard (inputs.count > 1) else
		{ continue }

		inputs
			.last!
			.trimmingCharacters(in: .whitespaces)
			.split(separator: " ")
			.map(String.init)
			.forEach { graph[$0, default: []].append(file) }
	}

	let changedFile = readLine()!

	return (graph, changedFile)
}

func compileSequence(of file: File, in graph: Graph) -> [File]
{
	var sequence: [File] = []
	var recompiled: Set<File> = []

	func recompile(_ file: File)
	{
		guard (!recompiled.contains(file)) else
		{ return }

		recompiled.insert(file)
		graph[file]!.forEach(recompile)
		sequence.append(file)
	}

	recompile(file)

	return sequence.reversed()
}
