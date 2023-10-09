/**
 * Class Field Trip
 * @see https://open.kattis.com/problems/classfieldtrip
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <string>
#include <string_view>

using namespace std;

auto merge(string_view a, string_view b) -> string
{
	string result{};

	const auto m{ a.size() };
	const auto n{ b.size() };

	// Reserve space for optimization
	result.reserve(m + n);

	size_t i{ 0 };
	size_t j{ 0 };

	while ((i < m) and (j < n))
	{
		if (a[i] < b[j])
		{
			result.push_back(a[i]);
			i++;
		}
		else
		{
			result.push_back(b[j]);
			j++;
		}
	}

	// Append the remaining characters.
	result.append(a.substr(i));
	result.append(b.substr(j));

	return result;
}

auto main() -> int
{
    string annsList;
		string bensList;

    // Get the two lists
    cin >> annsList;
    cin >> bensList;

    // Merge the two lists
    cout << merge(annsList, bensList) << '\n';

    return 0;
}
