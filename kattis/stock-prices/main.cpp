/**
 * Stock Prices
 * @see https://open.kattis.com/problems/stockprices
 *
 * @author Danial Haseeb
*/

#include <iostream>
#include <queue>
#include <string>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// The number of test cases.
	int cases;

	cin >> cases;

	for (int i{}; i < cases; ++i)
	{
		/// The number of orders.
		int n;

		cin >> n;

		/// The lowest price at which someone is willing to sell a share of a stock.
		int a{};

		/// The highest price at which someone is willing to buy a share of a stock.
		int b{};

		/// The price at which the last deal was established.
		int s{};

		for (int j{}; j < n; ++j)
		{
			/// Either "buy" or "sell".
			string orderType{};

			/// The number of shares of a stock someone wishes to buy or to sell.
			int x;

			/// The desired price.
			int y;

			// Read input.
			cin >> orderType >> x >> y;


		}
	}

	return 0;
}
