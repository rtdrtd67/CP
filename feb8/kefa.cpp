#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int res = 1;
    int n, prev, cur;
    int count = 1;
    cin >> n >> prev;
    for (int i = 1; i < n; i++) {
        cin >> cur;
        if (cur < prev) count = 1;
        else count++;
        prev = cur;
        res = max(res, count);
    }
    cout << res << endl;
    return 0;
}