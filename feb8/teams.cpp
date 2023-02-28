#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int n, k;

int help(vector<int>& dp, vector<vector<int>>& groups, vector<int>& students, int i, int num) {
    cout << groups[0][0] << " " << groups[0][1] << endl;
    if (i >= n) return num;
    // if (j >= k) return help(dp, groups, students, i+1, 0, num);
    if (dp[i] != -1) return dp[i];
    int cur = students[i];
    for (int j = 0; j < k; j++) {
        if (groups[j][0] == -1) {
            cout << "here\n";
            vector<vector<int>> groups1(groups);
            groups[j][0] = cur;
            groups[j][1] = cur;
            cout << groups1[0][0] << endl;
            dp[i] = max(dp[i], max(help(dp, groups1, students, i+1, num), help(dp, groups, students, i+1, num+1)));
            groups[j][0] = -1;
            groups[j][1] = -1;
        }
        else if ((cur >= groups[j][1]-5) && (cur <= groups[j][0]+5)) {
            int prev1, prev2;
            vector<vector<int>> groups1(groups);
            prev1 = groups[j][0];
            prev2 = groups[j][1];
            groups[j][0] = min(cur, groups[j][0]);
            groups[j][1] = max(cur, groups[j][1]);
            cout << groups1[0][0] << " " << groups1[0][1] << " " << groups[0][0] << " " << groups[0][1] << " " << num << endl;
            cout << i << endl;
            cout << help(dp, groups, students, i+1, num+1) << endl;
            dp[i] = max(dp[i], max(help(dp, groups1, students, i+1, num), help(dp, groups, students, i+1, num+1)));
            cout << dp[i] << endl;
            groups[j][0] = prev1;
            groups[j][1] = prev2;
        }        
    }
    // cout << groups[0][0] << " " << groups[0][1] << endl;
    dp[i] = max(dp[i], help(dp, groups, students, i+1, num));  
    
    // else {
    //     dp[i][j] = max(dp[i][j], noadd);
    //     return dp[i][j];
    // }
    // dp[i][j] = max(dp[i][j], max(noadd, help(dp, groups, students, i+1, j, num+1)));
    return dp[i];
}

int main() {
    cin >> n >> k;
    vector<int> students;
    int cur;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        students.push_back(cur);
    }
    vector<int> p(2, -1);
    vector<int> dp(n, -1);
    vector<vector<int>> groups(k, p);
    cout << help(dp, groups, students, 0, 0) << endl;
    // cout << best << endl;
    return 0;
}