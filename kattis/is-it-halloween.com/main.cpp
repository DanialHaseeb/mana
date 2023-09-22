/**
 * IsItHalloween.com
 * @see https://open.kattis.com/problems/isithalloween
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <string>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string month;
	int day;

	cin >> month >> day;

	cout << ((month == "OCT" && day == 31) || (month == "DEC" && day == 25) ? "yup\n" : "nope\n");

	return 0;
}
