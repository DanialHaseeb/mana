/**
 * Calculating Dart Scores
 * @see https://open.kattis.com/problems/calculatingdartscores
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <array>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t n;
	cin >> n;

	array scores
	{
		"single 1\n",
		"double 1\n",
		"triple 1\n",
		"double 2\n",
		"single 5\n",
		"triple 2\n",
		"single 7\n",
		"double 4\n",
		"triple 3\n",
		"double 5\n",
		"single 11\n",
		"triple 4\n",
		"single 13\n",
		"double 7\n",
		"triple 5\n",
		"double 8\n",
		"single 17\n",
		"triple 6\n",
		"single 19\n",
		"double 10\n",
		"triple 7\n",
		"double 11\n",
		"single 1\ndouble 11\n",
		"triple 8\n",
		"single 1\ntriple 8\n",
		"double 13\n",
		"triple 9\n",
		"double 14\n",
		"single 1\ndouble 14\n",
		"triple 10\n",
		"single 1\ntriple 10\n",
		"double 16\n",
		"triple 11\n",
		"double 17\n",
		"single 1\ndouble 17\n",
		"triple 12\n",
		"single 1\ntriple 12\n",
		"double 19\n",
		"triple 13\n",
		"double 20\n",
		"single 1\ndouble 20\n",
		"triple 14\n",
		"single 1\ntriple 14\n",
		"double 1\ntriple 14\n",
		"triple 15\n",
		"single 1\ntriple 15\n",
		"double 1\ntriple 15\n",
		"triple 16\n",
		"single 1\ntriple 16\n",
		"double 1\ntriple 16\n",
		"triple 17\n",
		"single 1\ntriple 17\n",
		"double 1\ntriple 17\n",
		"triple 18\n",
		"single 1\ntriple 18\n",
		"double 1\ntriple 18\n",
		"triple 19\n",
		"single 1\ntriple 19\n",
		"double 1\ntriple 19\n",
		"triple 20\n",
		"single 1\ntriple 20\n",
		"double 1\ntriple 20\n",
		"triple 1\ntriple 20\n",
		"double 2\ntriple 20\n",
		"double 4\ntriple 19\n",
		"triple 2\ntriple 20\n",
		"double 5\ntriple 19\n",
		"double 4\ntriple 20\n",
		"triple 3\ntriple 20\n",
		"double 5\ntriple 20\n",
		"double 7\ntriple 19\n",
		"triple 4\ntriple 20\n",
		"double 8\ntriple 19\n",
		"double 7\ntriple 20\n",
		"triple 5\ntriple 20\n",
		"double 8\ntriple 20\n",
		"double 10\ntriple 19\n",
		"triple 6\ntriple 20\n",
		"double 11\ntriple 19\n",
		"double 10\ntriple 20\n",
		"triple 7\ntriple 20\n",
		"double 11\ntriple 20\n",
		"double 13\ntriple 19\n",
		"triple 8\ntriple 20\n",
		"double 14\ntriple 19\n",
		"double 13\ntriple 20\n",
		"triple 9\ntriple 20\n",
		"double 14\ntriple 20\n",
		"double 16\ntriple 19\n",
		"triple 10\ntriple 20\n",
		"double 17\ntriple 19\n",
		"double 16\ntriple 20\n",
		"triple 11\ntriple 20\n",
		"double 17\ntriple 20\n",
		"double 19\ntriple 19\n",
		"triple 12\ntriple 20\n",
		"triple 19\ndouble 20\n",
		"double 19\ntriple 20\n",
		"triple 13\ntriple 20\n",
		"double 20\ntriple 20\n",
		"single 1\ndouble 20\ntriple 20\n",
		"triple 14\ntriple 20\n",
		"single 1\ntriple 14\ntriple 20\n",
		"double 1\ntriple 14\ntriple 20\n",
		"triple 15\ntriple 20\n",
		"single 1\ntriple 15\ntriple 20\n",
		"double 1\ntriple 15\ntriple 20\n",
		"triple 16\ntriple 20\n",
		"single 1\ntriple 16\ntriple 20\n",
		"double 1\ntriple 16\ntriple 20\n",
		"triple 17\ntriple 20\n",
		"single 1\ntriple 17\ntriple 20\n",
		"double 1\ntriple 17\ntriple 20\n",
		"triple 18\ntriple 20\n",
		"single 1\ntriple 18\ntriple 20\n",
		"double 1\ntriple 18\ntriple 20\n",
		"triple 19\ntriple 20\n",
		"single 1\ntriple 19\ntriple 20\n",
		"double 1\ntriple 19\ntriple 20\n",
		"triple 20\ntriple 20\n",
		"single 1\ntriple 20\ntriple 20\n",
		"double 1\ntriple 20\ntriple 20\n",
		"triple 1\ntriple 20\ntriple 20\n",
		"double 2\ntriple 20\ntriple 20\n",
		"double 4\ntriple 19\ntriple 20\n",
		"triple 2\ntriple 20\ntriple 20\n",
		"double 5\ntriple 19\ntriple 20\n",
		"double 4\ntriple 20\ntriple 20\n",
		"triple 3\ntriple 20\ntriple 20\n",
		"double 5\ntriple 20\ntriple 20\n",
		"double 7\ntriple 19\ntriple 20\n",
		"triple 4\ntriple 20\ntriple 20\n",
		"double 8\ntriple 19\ntriple 20\n",
		"double 7\ntriple 20\ntriple 20\n",
		"triple 5\ntriple 20\ntriple 20\n",
		"double 8\ntriple 20\ntriple 20\n",
		"double 10\ntriple 19\ntriple 20\n",
		"triple 6\ntriple 20\ntriple 20\n",
		"double 11\ntriple 19\ntriple 20\n",
		"double 10\ntriple 20\ntriple 20\n",
		"triple 7\ntriple 20\ntriple 20\n",
		"double 11\ntriple 20\ntriple 20\n",
		"double 13\ntriple 19\ntriple 20\n",
		"triple 8\ntriple 20\ntriple 20\n",
		"double 14\ntriple 19\ntriple 20\n",
		"double 13\ntriple 20\ntriple 20\n",
		"triple 9\ntriple 20\ntriple 20\n",
		"double 14\ntriple 20\ntriple 20\n",
		"double 16\ntriple 19\ntriple 20\n",
		"triple 10\ntriple 20\ntriple 20\n",
		"double 17\ntriple 19\ntriple 20\n",
		"double 16\ntriple 20\ntriple 20\n",
		"triple 11\ntriple 20\ntriple 20\n",
		"double 17\ntriple 20\ntriple 20\n",
		"double 19\ntriple 19\ntriple 20\n",
		"triple 12\ntriple 20\ntriple 20\n",
		"triple 19\ndouble 20\ntriple 20\n",
		"double 19\ntriple 20\ntriple 20\n",
		"triple 13\ntriple 20\ntriple 20\n",
		"double 20\ntriple 20\ntriple 20\n",
		"impossible\n",
		"triple 14\ntriple 20\ntriple 20\n",
		"impossible\n",
		"impossible\n",
		"triple 15\ntriple 20\ntriple 20\n",
		"impossible\n",
		"impossible\n",
		"triple 16\ntriple 20\ntriple 20\n",
		"impossible\n",
		"impossible\n",
		"triple 17\ntriple 20\ntriple 20\n",
		"impossible\n",
		"impossible\n",
		"triple 18\ntriple 20\ntriple 20\n",
		"impossible\n",
		"impossible\n",
		"triple 19\ntriple 20\ntriple 20\n",
		"impossible\n",
		"impossible\n",
		"triple 20\ntriple 20\ntriple 20\n",
	};

	cout << scores[n - 1];

	return 0;
}