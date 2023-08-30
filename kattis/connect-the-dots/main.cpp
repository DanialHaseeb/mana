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

using namespace std;

/**
 * Connects the dots in an image.
 *
 * @param image The image to be processed.
 */
auto connect(const vector<string>& image)
{
	/// The height of the image.
	const auto height{ image.size() };

	/// The width of the image.
	const auto width{ image[0].size() };

	/// The number of dots in the image.
	auto dots{ 0 };

	for (size_t i{}; i < height; ++i)
	{
		for (size_t j{}; j < width; ++j)
		{
			const auto dot{ image[i][j] };

			// If there is no dot at this location, do nothing.
			if (dot == '.')
			{ continue; }

			// Otherwise, increment the number of dots.
			++dots;


		}
	}
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
			connect(image);

			// Reset the image for the next test case.
			image.clear();

			// Leave a blank line between test cases.
			cout << '\n';

			continue;
		}

		image.push_back(row);
	}

	// Connect the dots for the last image.
	connect(image);

	return 0;
}
