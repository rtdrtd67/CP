#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n, a, b, x;
    cin >> n >> a >> b;
    vector<int> A;
    vector<int> B;
    for (int i = 0; i < a; i++) {
        cin >> x;
        A.push_back(x);
    }
    for (int i = 0; i < b; i++) {
        cin >> x;
        B.push_back(x);
    }
    int bob = 0, alice = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int a1 = A[i % a];
        int b1 = B[i % b];
        if (a1 == 0) {
            if (b1 == 1 || b1 == 4) bob++;
            else if (b1 != 0) alice++;
        }
        if (a1 == 1) {
            if (b1 == 2 || b1 == 4) bob++;
            else if (b1 != 1) alice++;
        }
        if (a1 == 2) {
            if (b1 == 0 || b1 == 3) bob++;
            else if (b1 != 2) alice++;
        }
        if (a1 == 3) {
            if (b1 == 0 || b1 == 1) bob++;
            else if (b1 != 3) alice++;
        }
        if (a1 == 4) {
            if (b1 == 2 || b1 == 3) bob++;
            else if (b1 != 4) alice++;
        }
    }
    cout << alice << " " << bob << endl;
    return 0;
}