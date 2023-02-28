#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void dst(vector<int>& x, vector<int>& y) {
    int dist = 0;
    int i = 0;
    int j = 0;
    int n = x.size();
    int m = y.size();
    while (i < n && j < m) {
        if (y[j] >= x[i]) {
            dist = max(j-i, dist);
            j++;
        }
        else i++;
    }
    cout << "The maximum distance is " << dist << endl;
}

int main() {
    int n, len;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> len;
        vector<int> x;
        vector<int> y;
        int cur;
        for (int j = 0; j < len; j++) {
            cin >> cur;
            x.push_back(cur);
        }
        for (int j = 0; j < len; j++) {
            cin >> cur;
            y.push_back(cur);
        }
        dst(x,y);
    }
    return 0;
}