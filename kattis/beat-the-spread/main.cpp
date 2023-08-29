/**
 * Beat the Spread!
 * @see https://open.kattis.com/problems/beatspread
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <algorithm>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// The number of test cases.
  int n{};

  cin >> n;

  for (int i = 0; i < n; ++i)
	{
		/// The sum of the two scores.
		int s{};

		/// The difference of the two scores.
		int d{};

    cin >> s >> d;

		/**
		 * Whether the sum of the sum and difference is even.
		 *
		 * This must always be the case because the sum and difference are both integers.
		 *
		 * @example s = 10, d = 4  ==>  (10 + 4) % 2 = 0
		 *
		 * @see https://en.wikipedia.org/wiki/Parity_(mathematics)
		*/
		const auto sumIsEven{ (s + d) % 2 == 0 };

    if ((s < d) or (not sumIsEven))
		{
      cout << "impossible\n";
      continue;
    }

		/// The first score.
    const auto a{ (s + d) / 2 };

		/// The second score.
    const auto b{ s - a };

		// Output the scores in ascending order.
    cout << max(a, b) << ' ' << min(a, b) << '\n';
  }

	return 0;
}
