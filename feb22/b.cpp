#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, m, t;
    string s;
    cin >> n >> m;
    ll ones = (ll)2e31-1;
    ll zeroes = 0;
    vector<string> logic;
    vector<int> ops;
    for (int i = 0; i < n; i++) {
        cin >> s >> t;
        logic.push_back(s);
        ops.push_back(t);
        if (s == "AND") {
            ones &= t;
            zeroes &= t;
        }
        else if (s == "OR") {
            ones |= t;
            zeroes |= t;
        }
        else {
            ones ^= t;
            zeroes ^= t;
        }
    }
    vector<int> best(32, 0);
    for (int i = 0; i < 32; i++) {
        int obit = ones & 1;
        int zbit = zeroes & 1;
        if (obit && !zbit) best[i] = 1;
        ones >>= 1;
        zeroes >>= 1;
    }
    ll initial = 0;
    int idx = -1;
    for (int i = 0; i < 32; i++) {
        if (best[i] && (1 << i) <= m) idx = i;
        if ((1 << i) > m) break;
    }
    for (int i = idx; i >= 0; i--) {
        if (initial + (best[i] << i) > m) break;
        initial += best[i] << i;
    }
    for (int i = 0; i < n; i++) {
        int t = ops[i];
        if (logic[i] == "AND") initial &= t;
        else if (logic[i] == "OR") initial |= t;
        else initial ^= t;
    }
    cout << initial << endl;
    return 0;
}