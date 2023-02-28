#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    int cur = 0;
    int res = 0;
    bool seen = false;
    vector<vector<int>> stage(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cur;
            stage[i].push_back(cur);
        }
    }
    for (int i = 0; i < n; i++) {
        cur = 0;
        for (int j = 0; j < m; j++) {
            if (stage[i][j] == 1) {
                res += cur;
                cur = 0;
            }
            else cur++;
        }
    }
    for (int i = 0; i < n; i++) {
        cur = 0;
        for (int j = m-1; j >= 0; j--) {
            if (stage[i][j] == 1) {
                res += cur;
                cur = 0;
            }
            else cur++;
        }
    }
    for (int i = 0; i < m; i++) {
        cur = 0;
        for (int j = 0; j < n; j++) {
            if (stage[j][i] == 1) {
                res += cur;
                cur = 0;
            }
            else cur++;
        }
    }
    for (int i = 0; i < m; i++) {
        cur = 0;
        for (int j = n-1; j >= 0; j--) {
            if (stage[j][i] == 1) {
                res += cur;
                cur = 0;
            }
            else cur++;
        }
    }
    cout << res << endl;
    return 0;
}