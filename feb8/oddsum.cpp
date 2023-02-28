#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, minabs, sum, cur;
    minabs = 1e9;
    sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cur;
        if (cur > 0) sum += cur;
        if (cur % 2 != 0) {
            minabs = min(minabs, abs(cur));
        }
    }
    if (sum % 2 != 0) cout << sum << endl;
    else cout << sum-minabs << endl;
    return 0;
}