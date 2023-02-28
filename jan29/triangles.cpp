#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> lens;
    for (int i = 0; i < n; i++) {
        long long l;
        cin >> l;
        lens.push_back(l);
    }
    sort(lens.begin(), lens.end());
    int m = lens.size();
    bool one = false, two = false;
    long long res = 0;
    for (int i = m-1; i >= 2; i--) {
        int l1 = lens[i], l2 = lens[i-1], l3 = lens[i-2];
        if (l2 + l3 > l1) {
            res += l1 + l2 + l3;
            lens.erase(lens.begin()+i);
            lens.erase(lens.begin()+(i-1));
            lens.erase(lens.begin()+(i-2));
            one = true;
            break;
        } 
    }
    m = lens.size();
    for (int i = m-1; i >= 2; i--) {
        int l1 = lens[i], l2 = lens[i-1], l3 = lens[i-2];
        if (l2 + l3 > l1) {
            res += l1 + l2 + l3;
            two = true;
            break;
        } 
    }
    if (one && two) cout << res << endl;
    else cout << 0 << endl;
    return 0;
}