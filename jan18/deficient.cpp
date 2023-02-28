#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int divisors(int n) {
    int res = 1;
    int d = 2;
    while (d*d <= n) {
        if (n % d == 0) {
            res += d;
            if (d != n/d) res += n/d;
        }
        d++;
    }
    return res;
}
int main() {
    int n;
    int num;
    cin >> n;    
    for (int i = 0; i < n; i++) {
        cin >> num;
        int sum = divisors(num);
        if (sum > num) cout << num << " is an abundant number.\n";
        else if (sum == num) cout << num << " is a perfect number.\n";
        else cout << num << " is a deficient number.\n";
    }
    return 0;
}