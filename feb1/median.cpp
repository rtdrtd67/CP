#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ll t, n, s, med;
    cin >> t;
    for (ll i = 0; i < t; i++) {
        cin >> n >> s;
        ll elems;
        if (n % 2 == 1) elems = n-n/2;
        else elems = n-n/2+1;
        // ll med = s/2;
        // ll diff = med/2;
        // while (med*elems > n && (med+1)*elems ) {

        // }
        cout << s/elems << endl;
    }
    return 0;
}