//
//  CPR Number
//  https://open.kattis.com/problems/cprnummer
//
//  Created by Danial Haseeb on 08/10/2023.
//

extension String
{
	var isValidCPR: Bool
	{
		// Convert CPR string into array of digits.
		let digits = self.compactMap { Int(String($0)) }

		// Weights for each position in the CPR number.
		let weights = [4, 3, 2, 7, 6, 5, 4, 3, 2, 1]

		// Calculate the sum of digits multiplied by their corresponding weight.
		let totalSum = zip(digits, weights)
			.map { $0 * $1 }
			.reduce(0, +)

		// Check if the sum is divisible by 11.
		return totalSum % 11 == 0
	}
}

let number = readLine()!
print(number.isValidCPR ? "1" : "0")
