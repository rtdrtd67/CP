#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int rem = n % 4;
    n -= rem*5;
    if (n < 0) cout << 0 << endl;
    else {
        int num = n/4;
        cout << num/5+1 << endl;
    }
    return 0;
}