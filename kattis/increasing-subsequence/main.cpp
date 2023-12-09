#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

auto main() -> int
{
  while (true)
	{
    size_t n;
    cin >> n;

    if (n == 0)
		{ break; }

    vector<int> sequence(n);
    vector<size_t> lengths(n, 1);
    vector<vector<int>> indices(n);

    for (auto i{ 0 }; i < n; ++i)
		{ cin >> sequence[i]; }

    auto maxLength{ 1 };
    auto maxIndex
		{ static_cast<size_t>(min_element(sequence.begin(), sequence.end()) - sequence.begin()) };

    for (size_t i{ 0 }; i < n; ++i)
		{
      indices[i].push_back(sequence[i]);

      for (size_t j{ 0 }; j < i; ++j)
			{
				const auto candidate{ lengths[j] + 1 };

        if (sequence[j] > sequence[i])
				{ continue; }

        if ((candidate == maxLength) and (indices[maxIndex] > indices[j]))
				{ maxIndex = i; }

        if (sequence[j] >= sequence[i])
				{ continue; }

        if ((candidate > lengths[i]) or ((candidate == lengths[i]) and (indices[i] > indices[j])))
				{
          indices[i].clear();

          for (const auto node : indices[j])
					{ indices[i].push_back(node); }

          indices[i].push_back(sequence[i]);
        }

        if (candidate > lengths[i])
				{
          lengths[i] = candidate;

          if (lengths[i] > maxLength)
					{
            maxLength = lengths[i];
            maxIndex = i;
          }
        }
      }
    }

    cout << maxLength << ' ';

    for (const auto value : indices[maxIndex])
		{ cout << value << ' '; }

    cout << '\n';
  }

  return 0;
}
