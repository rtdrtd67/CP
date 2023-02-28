#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool isPrime(int n) {
    int k = sqrt(n);
    for (int i = 2; i <= k; i++) {
        if (n % i == 0) return true;
    }
    return false;
}

int fib(int i, vector<int>& fibs, unordered_set<int>& nums) {
    if (i < fibs.size()) return fibs[i];
    int num = fib(i-1, fibs, nums) + fib(i-2, fibs, nums);
    fibs.push_back(num);
    nums.insert(num);
    return num;
}

int main() {
    vector<int> fibs;
    unordered_set<int> nums;
    fibs.push_back(1), fibs.push_back(1);
    nums.insert(1);
    fib(26, fibs, nums);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int cur;
        cin >> cur;
        if (isPrime(cur) && nums.count(cur)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}