#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int t, n;
    cin >> t;
    for (int k = 0; k < t; k++) {
        cin >> n;
        int cur;
        vector<int> A;
        for (int i = 0; i < n; i++) {
            cin >> cur;
            if (cur < i+1) {
                A.push_back(cur);
            }
        }
        n = A.size();
        
    }
}