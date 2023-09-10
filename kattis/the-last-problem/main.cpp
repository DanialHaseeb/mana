/**
 * The Last Problem
 * Problem URL: https://open.kattis.com/problems/thelastproblem
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <string>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations
	ios::sync_with_stdio(0);
	cin.tie(0);

	/// The name of the one you will bid farewell to.
	string name{};

	getline(cin, name);

	cout << "Thank you, " << name << ", and farewell!\n";

	return 0;
}
