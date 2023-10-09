//
//  Datum
//  https://open.kattis.com/problems/datum
//
//  Created by Danial Haseeb on 09/10/2023.
//

let days: [Int: Int] =
[
	   1:   0,   2:  31,   3:  59,   4:  90,   5: 120,   6: 151,
	   7: 181,   8: 212,   9: 243,  10: 273,  11: 304,  12: 334
]

let input = readLine()!
	.split(separator: " ")
	.map { Int($0)! }

let (d, m) = (input[0], input[1])

let day = (days[m]! + d + 3) % 7

switch day
{
	case 0: print("Sunday")
	case 1: print("Monday")
	case 2: print("Tuesday")
	case 3: print("Wednesday")
	case 4: print("Thursday")
	case 5: print("Friday")
	case 6: print("Saturday")

	default: break;
}
