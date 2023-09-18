/**
 * Aaah!
 * @see https://open.kattis.com/problems/aaah
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

	string john;
	string doctor;

	cin >> john >> doctor;

	cout << (john.length() >= doctor.length() ? "go\n" : "no\n");

	return 0;
}
