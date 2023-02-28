#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ammo1 = 0;
    int ammo2 = 0;
    int score = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            if (ammo1 > 0) {
                score++;
                ammo1--;
            }
            else ammo1++;
            ammo2++;
        }
        else if (s[i] == 'F') {
            if (ammo2 == 0) {
                if (ammo1 > 0) {
                    score++;
                    ammo1--;
                }
                else ammo1++;
            }
            else ammo2--;
        }
        else {
            ammo1++;
        }
    }
    cout << score << endl;
    return 0;
}