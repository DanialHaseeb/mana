/**
 * Zagrade
 * @see https://open.kattis.com/problems/zagrade
 *
 * @author Danial Haseeb
 */

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

auto main() -> int
{
	// Optimise I/O operations.
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string expression{};
	cin >> expression;
	const auto n{ expression.size() };

	vector<pair<size_t, size_t>> pairs;
	stack<size_t> indices;

	for (size_t i{ 0 }; i < n; ++i)
	{
		if (expression[i] == '(')
		{ indices.push(i); }
		else if (expression[i] == ')')
		{
			pairs.push_back({ indices.top(), i });
			indices.pop();
		}
	}

	const auto m{ pairs.size() };

	set<string> expressions;

	const auto subsets{ static_cast<size_t>(1) << m };

	for (size_t i{ 1 }; i < subsets; ++i)
	{
		vector<bool> removed(n);

		for (size_t j{ 0 }; j < m; ++j)
		{
			if (i & (1 << j))
			{
				removed[pairs[j].first] = true;
				removed[pairs[j].second] = true;
			}
		}

		string validExpression{};

		for (size_t j{ 0 }; j < n; ++j)
		{
			if (not removed[j])
			{ validExpression += expression[j]; }
		}

		expressions.insert(validExpression);
	}

	for (const auto& expression : expressions)
	{ cout << expression << '\n'; }
}
