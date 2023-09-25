/**
 * Bijele
 * @see https://open.kattis.com/problems/bijele
 *
 * @author Danial Haseeb
 */

#include <iostream>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int kings;
	int queens;
	int rooks;
	int bishops;
	int knights;
	int pawns;

	cin >> kings >> queens >> rooks >> bishops >> knights >> pawns;

	cout
		<< 1 - kings   << ' '
		<< 1 - queens  << ' '
		<< 2 - rooks   << ' '
		<< 2 - bishops << ' '
		<< 2 - knights << ' '
		<< 8 - pawns   << '\n';

	return 0;
}
