#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int y, m, d;
        cin >> y >> m >> d;
        int age = 2007-y;
        if (m > 2) age--;
        else if (m == 2 && d > 27) age--;
        if (age >= 18) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}