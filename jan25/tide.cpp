#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    vector<int> scramble;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        scramble.push_back(t);
    }
    sort(scramble.begin(), scramble.end());
    int mid = (n-1)/2;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cout << scramble[mid-i/2] << " ";
        else cout << scramble[mid+(i+1)/2] << " ";
    }
    return 0;
}