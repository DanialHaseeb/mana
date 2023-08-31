/**
 * Connect the Dots
 * @see https://open.kattis.com/problems/connectthedots
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>
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

auto connectHorizontally(vector<string>& image,
	                       const size_t x1,
                         const size_t x2,
                         const size_t y)
{
	/// The start of the horizontal line.
	const auto start{ min(x1, x2) + 1 };

	/// The end of the horizontal line.
	const auto end{ max(x1, x2) - 1 };

	for (size_t i{ start }; i <= end; ++i)
	{
		if (image[y][i] == '|')
		{ image[y][i] = '+'; }
		else if (image[y][i] == '.')
		{ image[y][i] = '-'; }
	}
}

auto connectVertically(vector<string>& image,
                       const size_t y1,
                       const size_t y2,
                       const size_t x)
{
	/// The start of the horizontal line.
	const auto start{ min(y1, y2) + 1 };

	/// The end of the horizontal line.
	const auto end{ max(y1, y2) - 1 };

	for (size_t i{ start }; i <= end; ++i)
	{
		if (image[i][x] == '-')
		{ image[i][x] = '+'; }
		else if (image[i][x] == '.')
		{ image[i][x] = '|'; }
	}
}

auto connectDots(vector<string>& image,
                 const pair<size_t, size_t>& position1,
                 const pair<size_t, size_t>& position2)
{
	const auto [y1, x1]{ position1 };
	const auto [y2, x2]{ position2 };

	// If the dots are in the same row, connect them horizontally.
	if (y1 == y2)
	{ connectHorizontally(image, x1, x2, y1); }
	// If the dots are in the same column, connect them vertically.
	else
	{ connectVertically(image, y1, y2, x1); }
}

/**
 * Connects the dots in an image.
 *
 * @param image The image to be processed.
 */
auto connect(vector<string>& image, const array<char, 62>& Σ)
{
	/// A map of the coordinates of the dots in the image.
	auto coordinates{ locateDots(image) };

	for (size_t i{}; i < (coordinates.size() - 1); ++i)
	{
		/// The first dot to be connected.
		const auto dot1{ Σ[i] };

		/// The second dot to be connected.
		const auto dot2{ Σ[i + 1] };

		/// The coordinates of the first dot.
		const auto position1{ coordinates[dot1] };

		/// The coordinates of the second dot.
		const auto position2{ coordinates[dot2] };

		connectDots(image, position1, position2);
	}
}

auto print(const vector<string>& image)
{
	for (const auto& row : image)
	{ cout << row << '\n'; }
}

auto main() -> int
{
	/// The characters that represent the dots in an image.
	const array Σ
	{
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e',
		'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
		'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
		'Y', 'Z'
	};

	/// An image to be processed.
	vector<string> image;

	/// A row of an image.
	string row{};

	while (getline(cin, row))
	{
		if (row.empty())
		{
			// The image has been fully read.
			// The dots inside the image need to be connected now.
			connect(image, Σ);

			print(image);

			// Reset the image for the next test case.
			image.clear();

			// Leave a blank line between test cases.
			cout << '\n';

			continue;
		}

		image.push_back(row);
	}

	// Connect the dots for the last image.
	connect(image, Σ);

	print(image);

	return 0;
}
