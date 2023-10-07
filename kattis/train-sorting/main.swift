//
//  Train Sorting
//  https://open.kattis.com/problems/trainsorting
//
//  Created by Danial Haseeb on 07/10/2023.
//

/// The number of train cars.
let numCars = Int(readLine()!)!

/// The weights of the cars
var carWeights = Array<Int>(repeating: 0, count: numCars)

// Initialize the array to store the weights of the cars from the input.
for i in 0..<numCars
{ carWeights[i] = Int(readLine()!)! }

/// The longest train that can be formed
var maxLength = Int()

/// The length of Longest Increasing Subsequence ending at index i.
var lis = Array<Int>(repeating: 1, count: numCars)

/// The length of Longest Decreasing Subsequence ending at index i.
var lds = Array<Int>(repeating: 1, count: numCars)

// Iterate over the train cars in reverse order.
for i in (0..<numCars).reversed()
{
	// For each train car, compare it to every car coming after it.
	for j in (i+1..<numCars).reversed()
	{
		if (carWeights[j] > carWeights[i])
		{ lis[i] = max(lis[i], lis[j] + 1) }

		if (carWeights[j] < carWeights[i])
		{ lds[i] = max(lds[i], lds[j] + 1) }
	}

	// The maximum length train considering car[i] at the center will be the sum
	// of lis[i] and lds[i] minus 1.  We subtract 1 to prevent double-counting,
	// once in lis and once in lds.
	maxLength = max(maxLength, lis[i] + lds[i] - 1)
}

// Print the maximum length of train possible.
print(maxLength)
