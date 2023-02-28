#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> swifts;
    vector<int> sema;
    int best = 0;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        swifts.push_back(r);
    }
    for (int i = 0; i < n; i++) {
        int r;
        cin >> r;
        sum1 += swifts[i];
        sum2 += r;
        if (sum1 == sum2) best = i+1;
    }
    cout << best << "\n";
    return 0;
}