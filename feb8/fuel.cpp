#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int n = 0;
int v = 0;

// int trip(vector<vector<int>>& dp, int i, int cost, int fuel) {
//     if (i >= n) {
//         cout << "here\n";
//         return 0;
//     }
//     if (dp[i][fuel] != 1e9) return dp[i][fuel];
//     if (fuel > 0) dp[i][fuel] = min(dp[i][fuel], trip(dp, i+1, 0, fuel-1));
//     while (fuel < v) {
//         fuel++;
//         cost += i;
//         dp[i][fuel] = min(dp[i][fuel], cost+trip(dp, i+1, 0, fuel-1));
//     }
//     return dp[i][fuel];
// }

int main() {
    cin >> n >> v;
    int fuel = 0;
    int cost = 0;
    for (int i = 1; i <= n; i++) {
        int dist = n-i;
        while (fuel < dist && fuel < v) {
            fuel++;
            cost += i;
        }
        fuel--;
    }
    cout << cost << endl;
    // vector<int> gas(v+1, 1e9);
    // vector<vector<int>> dp(n+1, gas);
    // cout << trip(dp, 1, 0, 0) << endl;
    return 0;
}