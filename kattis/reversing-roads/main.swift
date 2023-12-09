//
//  Reversing Roads
//  https://open.kattis.com/problems/reversingroads
//
// 	Created by Danial Haseeb on 09/12/2023.
//

var testCase = 0
while let proposal = input()
{
	testCase += 1
	print("Case \(testCase): \(evaluation(of: proposal))")
}

typealias Location = Int
typealias Vertex = Location
typealias Edge = (Vertex, Vertex)
typealias Graph = ([Vertex], [Edge])

func input() -> Graph?
{
	guard let inputs = readLine()?.split(separator: " ").map({ Int($0)! }) else
	{ return nil }

	let (m, n) = (inputs[0], inputs[1])

	let vertices: [Vertex] = (0..<m).map { $0 }
	let edges: [Edge] = (0..<n).map
	{ _ in
		let inputs = readLine()!
			.split(separator: " ")
			.map { Int($0)! }
		return (inputs[0], inputs[1])
	}

	return (vertices, edges)
}

enum Result: CustomStringConvertible
{
	case valid
	case invalid
	case reverse(Edge)

	var description: String
	{
		switch self
		{
			case .valid:
				return "valid"
			case .invalid:
				return "invalid"
			case .reverse(let edge):
				return "\(edge.0) \(edge.1)"
		}
	}
}

func evaluation(of proposal: Graph) -> Result
{
	let components = stronglyConnectedComponents(of: proposal)

	guard (components.count != 1) else
	{ return .valid }

	let (vertices, edges) = proposal

	for i in edges.indices
	{
		let (u, v) = edges[i]
		var newEdges = edges
		newEdges[i] = (v, u)
		let newProposal = (vertices, newEdges)
		let newComponents = stronglyConnectedComponents(of: newProposal)

		if newComponents.count == 1
		{ return .reverse(edges[i]) }
	}

	return .invalid
}

func stronglyConnectedComponents(of graph: Graph) -> [Vertex: [Vertex]]
{
	var roots: [Vertex: Vertex] = [:]

	let inNeighbours = inNeighbours(of: graph)
	let outNeighbours = outNeighbours(of: graph)

	func visit(_ vertex: Vertex)
	{
		guard !visited.contains(vertex) else
		{ return }

		visited.insert(vertex)
		outNeighbours[vertex]?.forEach(visit)
		orderedVertices.append(vertex)
	}

	func assign(_ vertex: Vertex, to root: Vertex)
	{
		guard roots[vertex] == nil else
		{ return }

		roots[vertex] = root
		inNeighbours[vertex]?.forEach { assign($0, to: root) }
	}

	let (vertices, _) = graph
	var visited: Set<Vertex> = []
	var orderedVertices: [Vertex] = []

	vertices.forEach(visit)
	orderedVertices.reversed().forEach { assign($0, to: $0) }

	var components: [Vertex: [Vertex]] = [:]

	roots.forEach { components[$1, default: []].append($0) }

	return components
}

func inNeighbours(of graph: Graph) -> [Vertex: [Vertex]]
{
	let (vertices, edges) = graph

	var result: [Vertex: [Vertex]] = [:]

	vertices.forEach
	{(vertex) in
		result[vertex] = edges
			.filter { $0.1 == vertex }
			.map { $0.0 }
	}

	return result
}

func outNeighbours(of graph: Graph) -> [Vertex: [Vertex]]
{
	let (vertices, edges) = graph

	var result: [Vertex: [Vertex]] = [:]

	vertices.forEach
	{(vertex) in
		result[vertex] = edges
			.filter { $0.0 == vertex }
			.map { $0.1 }
	}

	return result
}
