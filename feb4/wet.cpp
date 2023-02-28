#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, m;
    cin >> n >> m;
    vector<char> a;
    vector<vector<char>> grid(n, a);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char c : s) grid[i].push_back(c);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'W') {
                if (i > 0 && grid[i-1][j] == '.') {
                    grid[i-1][j] = 'C';
                }
                if (i < n-1 && grid[i+1][j] == '.') {
                    grid[i+1][j] = 'C';
                }
                if (j > 0 && grid[i][j-1] == '.') {
                    grid[i][j-1] = 'C';
                }
                if (j < m-1 && grid[i][j+1] =='.') {
                    grid[i][j+1] = 'C';
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    return 0;
}