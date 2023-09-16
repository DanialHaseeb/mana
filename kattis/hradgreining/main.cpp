/**
 * Hraðgreining
 * @see https://open.kattis.com/problems/hradgreining
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

	string dna;
	cin >> dna;

	cout << ((dna.find("COV") != string::npos) ? "Veikur!\n" : "Ekki veikur!\n");

	return 0;
}
