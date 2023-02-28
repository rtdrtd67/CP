#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll t, n, x;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> x;
        ll cur;
        vector<ll> prices;
        for (int j = 0; j < n; j++) {
            cin >> cur;
            prices.push_back(cur);
        }
        sort(prices.begin(), prices.end());
        vector<ll> sums(n, 0);
        ll sum = 0;
        for (int j = 0; j < n; j++) {
            sum += prices[j];
            sums[j] = sum;
        }
        ll days = 0;
        ll res = 0;
        while (sums[0]+days <= x) {
            int lo = 0, hi = n, mid = n/2;
            while (lo < hi) {
                if (sums[mid]+(mid+1)*days > x) {
                    hi = mid-1;
                    mid = (lo+hi)/2;
                }
                else {
                    if (mid == n-1 || sums[mid+1]+(mid+2)*days > x) {
                        break;
                    }
                    lo = mid+1;
                    mid = (lo+hi)/2;
                }
                // cout << lo << " " << mid << " " << hi << endl;
            }
            if (mid != n-1 && sums[mid+1]+(mid+2)*days <= x) mid++;
            ll diff = x-(sums[mid]+(mid+1)*days);
            days += diff/(mid+1)+1;
            res += (mid+1)*((diff/(mid+1))+1);
        }
        cout << res << endl;
    }
    return 0;
}