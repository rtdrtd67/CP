#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

bool seven(int p) {
    while (p > 0) {
        if (p % 10 == 7) return true;
        p /= 10;
    }
    return false;
}

int main() {
    int n, x;
    cin >> n;
    int m = 1e7+1e4;
    vector<bool> sieve(m, false);
    unordered_map<int, int> h;
    for (int i = 7; i < m; i++) {
        if (sieve[i]) continue;
        if (!seven(i)) continue;
        int j = i;
        while (j < m) {
            sieve[j] = true;
            j += i;
        }
    }
    int prev = 1;
    for (int i = 2; i < m; i++) {
        if (sieve[i]) continue;
        h[prev] = i;
        prev = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (sieve[x]) cout << -1 << endl;
        else cout << h[x] << endl;
    }
    return 0;
}