/*
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
	int n{};

	cout << "Enter the number of digits after the decimal point for π: ";
	cin >> n;

	if (n > 15)
	{
		cout << "The maximum allowed value for n is 15.\n";
		return 1;
	}

	// Set precision to n digits after the decimal point
	cout << fixed << setprecision(n);

	// Print Pi value
	cout << "π (Pi) rounded to "
	     << n
			 << " digits after the decimal point is: "
			 << numbers::pi
			 << '\n';

	return 0;
}
