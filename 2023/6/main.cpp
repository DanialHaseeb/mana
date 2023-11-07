#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <climits>

using namespace std;
using Int = long long int;

Int minDisassemblyCost(const vector<Int>& modules) {
    auto n = modules.size();
    vector<vector<Int>> dp(n, vector<Int>(n, 0));
    vector<Int> prefixSum(n + 1, 0);

    // Calculate prefix sums for easy calculation of subarray sums
    for (size_t i = 0; i < n; ++i) {
        prefixSum[i + 1] = prefixSum[i] + modules[i];
    }

    // Calculate the minimum cost for each subarray
    for (size_t length = 2; length <= n; ++length) {
        for (size_t i = 0; i <= n - length; ++i) {
            auto j = i + length - 1;
            dp[i][j] = static_cast<Int>(LLONG_MAX);
            for (size_t k = i; k < j; ++k) {
                Int cost = dp[i][k] + dp[k + 1][j] + prefixSum[i + 1] + prefixSum[n] - prefixSum[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

auto main() -> int {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Int testCases;
    cin >> testCases;

    for (Int _{ 0 }; _ < testCases; ++_) {
        cin.ignore();
        string input{};
        getline(cin, input);
        istringstream ss{input};
        vector<Int> modules;
        Int x;
        while (ss >> x) {
            modules.push_back(x);
        }

        cout << minDisassemblyCost(modules) << '\n';
    }

    return 0;
}
