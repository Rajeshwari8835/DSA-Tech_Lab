#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>>& cost) {
    int n = cost.size();
    int total = 1 << n;

    vector<int> dp(total, INT_MAX);
    dp[0] = 0;

    for(int mask = 0; mask < total; mask++) {
        int worker = __builtin_popcount(mask);

        for(int task = 0; task < n; task++) {
            if(!(mask & (1 << task))) {
                int newMask = mask | (1 << task);
                dp[newMask] = min(dp[newMask],
                                  dp[mask] + cost[worker][task]);
            }
        }
    }

    return dp[total-1];
}