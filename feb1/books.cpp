#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, t, b;
    cin >> n >> t;
    vector<int> books;
    for (int i = 0; i < n; i++) {
        cin >> b;
        books.push_back(b);
    }
    queue<int> q;
    int best = 0;
    int sum = 0;
    vector<int> sums(n, 0);
    for (int i = n-i-1; i >= 0; i--) {
        sum += books[i];
        sums[i] = sum;
    }
    for (int i = 0; i < n; i++) {
        int num = n-i;
        int cur = sums[i];
        if (cur <= t) best = max(num, best);
        else {
            int lo = 0;
            int hi = n;
            int mid = n/2;
            while (lo < hi) {
                if (cur-sums[mid] > t) {
                    hi = mid-1;
                    mid = (lo+hi)/2;
                }
                else {
                    if (mid == n-1 || cur-sums[mid+1] > t) {
                        break;
                    }
                    lo = mid+1;
                    mid = (lo+hi)/2;
                }
                // cout << lo << " " << mid << " " << hi << endl;
            }
            if (mid != n-1 && cur-sums[mid+1] <= t) mid++;
            best = max(best, mid-i);
        }
    }
    cout << best << endl;
    return 0;
}