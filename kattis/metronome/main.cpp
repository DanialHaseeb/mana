/**
 * Metronome
 * @see https://open.kattis.com/problems/metronome
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <iomanip>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	double n;
	cin >> n;

	cout << fixed << setprecision(2) << n / 4.0 << '\n';

	return 0;
}
