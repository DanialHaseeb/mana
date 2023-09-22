/**
 * Connect the Dots
 * @see https://open.kattis.com/problems/connectthedots
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
// For std::pair.
#include <utility>
// For std::min and std::max.
#include <algorithm>

using namespace std;

/**
 * Locates the dots in an image.
 *
 * @param image The image to be processed.
 *
 * @return A map of the coordinates of the dots in the image.
 */
auto locateDots(const vector<string>& image)
-> unordered_map<char, pair<size_t, size_t>>
{
	/// The height of the image.
	const auto height{ image.size() };

	/// The width of the image.
	const auto width{ image[0].size() };

	/// A map of the coordinates of the dots in the image.
	unordered_map<char, pair<size_t, size_t>> coordinates;

	for (size_t i{}; i < height; ++i)
	{
		for (size_t j{}; j < width; ++j)
		{
			const auto dot{ image[i][j] };

			// If there is no dot at this location, do nothing.
			if (dot == '.')
			{ continue; }

			// Store the coordinates of the dot.
			coordinates[dot] = { i, j };
		}
	}

	return coordinates;
}

auto connect(vector<string>& image, const array<char, 62>& dots)
{
	auto coordinates{ locateDots(image) };

	for (size_t i{}; i < (coordinates.size() - 1); ++i)
	{
		const auto dot1{ dots[i] };
		const auto dot2{ dots[i + 1] };

		const auto& [y1, x1] = coordinates[dot1];
		const auto& [y2, x2] = coordinates[dot2];

		if (y1 == y2)
		{
			const auto y{ y1 };
			const auto start{ min(x1, x2) };
			const auto end{ max(x1, x2) };

			for (auto j{ start }; j < end; ++j)
			{
				const auto pixel{ image[y][j] };

				if (pixel == '.')
				{ image[y][j] = '-'; }
				else if (pixel == '|')
				{ image[y][j] = '+'; }
			}
		}
		else
		{
			const auto x{ x1 };
			const auto start{ min(y1, y2) };
			const auto end{ max(y1, y2) };

			for (auto j{ start }; j < end; ++j)
			{
				const auto pixel{ image[j][x] };

				if (pixel == '.')
				{ image[j][x] = '|'; }
				else if (pixel == '-')
				{ image[j][x] = '+'; }
			}
		}
	}
}

/**
 * Prints the image to standard output.
 *
 * @param image The image to be printed.
*/
auto output(const vector<string>& image)
{
	for (const auto& row : image)
	{ cout << row << '\n'; }
}

auto main() -> int
{
	// Optimise I/O operations
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const array dots
	{
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e',
		'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
		'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z'
	};

	vector<string> image;

	string row;

	while (getline(cin, row))
	{
		if (row.empty())
		{
			connect(image, dots);

			output(image);

			image.clear();

			// Print a blank line between test cases.
			cout << '\n';
		}
		else
		{ image.push_back(row); }
	}

	connect(image, dots);

	output(image);

	return 0;
}
