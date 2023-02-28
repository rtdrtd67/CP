#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> lengths(2001, 0);
    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        lengths[l]++;
    }
    vector<int> sums(4001, 0);
    for (int i = 1; i < 2001; i++) {
        for (int j = i; j < 2001; j++) {
            if (i == j) sums[i+i] += (lengths[i]/2);
            else sums[i+j] += min(lengths[i], lengths[j]);
        }
    }
    int lng = 0;
    for (int i = 1; i < 4001; i++) {
        lng = max(lng, sums[i]);
    }
    int diff = 0;
    for (int i = 1; i < 4001; i++) {
        if (sums[i] == lng) diff++;
    }
    cout << lng << " " << diff;
    return 0;
}