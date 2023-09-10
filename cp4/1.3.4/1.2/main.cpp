/**
 * Competitive Prgoramming 4
 *
 * 1.3.4.1.2
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <iomanip>
#include <numbers>

using namespace std;

auto main() -> int
{
	int n;
	cin >> n;

	// Set precision to n digits after the decimal point
	cout << fixed << setprecision(n);

	// Print Pi value
	cout << numbers::pi << '\n';

	return 0;
}
