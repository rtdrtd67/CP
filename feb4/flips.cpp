#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int help(vector<int>& arr, int i, int bit, vector<vector<int>>& dp) {
    int n = arr.size();
    bool flag = true;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[i-1]) {
            flag = false;
            break;
        }
    }
    if (flag) {
        cout << "here" << endl;
        return 0;
    }
    if (i >= n) return 1e9;
    if (bit >= 30) return help(arr, i+1, 0, dp);
    if (dp[i][bit] != -1) {
        cout << "dp" << endl;
        return dp[i][bit];
    }
    int mask = 1 << bit;
    vector<int> arr1;
    for (int j : arr) arr1.push_back(j);
    arr1[i] ^= mask;
    for (int j : arr1) cout << j << " ";
    cout << endl;
    dp[i][bit] = min(1+help(arr1, i, bit+1, dp), help(arr, i, bit+1, dp));
    return dp[i][bit];
}

int main() {
    int n;
    cin >> n;
    int a;
    vector<int> arr;
    for (int i = 0; i < n; i++) {
        cin >> a;
        arr.push_back(a);
    }
    vector<int> row(30, -1);
    vector<vector<int>> dp(n, row);
    cout << help(arr, 0, 0, dp) << endl;
    return 0;
}