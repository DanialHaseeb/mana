/**
 * Baby Bites
 * @see https://open.kattis.com/problems/babybites
 *
 * @author Danial Haseeb
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/// The number of bites Arild receives.
	int n{};

	cin >> n;

	/// The sequence of bites or mumbles
	vector<int> a;

	for (int i{}; i < n; ++i)
	{
		string word{};
		cin >> word;

		// If word is "mumble", push -1 as a placeholder,
    // otherwise push the integer value of word.
		if (word == "mumble")
		{ a.push_back(-1); }
		else
		{ a.push_back(stoi(word)); }
	}

	// Check if the length of a does not match the expected length
	if (a.size() != n)
	{
		cout << "something is fishy\n";
		return 0;
	}

	/// Variable to track the expected value in sequence
	auto realCount{ 1 };

	// Check the sequence to ensure correctness
	for (auto arlidCount : a)
	{
		// If the count does not match the expected value and is not a mumble,
    // output an error
		if ((arlidCount != realCount) and (arlidCount != -1))
		{
			cout << "something is fishy\n";
			return 0;
		}

		++realCount;
	}

	// If the loop completes without an error, the sequence makes sense
	cout << "makes sense\n";

	return 0;
}
