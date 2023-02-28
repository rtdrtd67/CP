#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int strhash(const string& s)
{
    long long p = 29791, m = 1e9 + 7;
    long long hash_so_far = 0;
    long long p_pow = 1;
    const long long n = s.size();
    for (long long i = 0; i < n; i++) {
        hash_so_far = (hash_so_far + (s[i] - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_so_far;
}

int main() {
    int x, y, g;
    cin >> x;
    unordered_map<int, vector<vector<string>>> groups;
    vector<vector<string>> tg;
    vector<vector<string>> apart;
    for (int i = 0; i < x; i++) {
        string s1, s2;
        cin >> s1, cin >> s2;
        vector<string> t;
        t.push_back(s1), t.push_back(s2);
        tg.push_back(t);
    }
    cin >> y;
    for (int i = 0; i < y; i++) {
        string s1, s2;
        cin >> s1, cin >> s2;
        vector<string> t;
        t.push_back(s1), t.push_back(s2);
        apart.push_back(t);
    }
    cin >> g;
    int res = 0;
    for (int i = 0; i < g; i++) {
        vector<string> group1, group2, group3;
        string s1, s2, s3;
        cin >> s1, cin >> s2, cin >> s3;
        group1.push_back(s1), group1.push_back(s2);
        group2.push_back(s1), group2.push_back(s3);
        group3.push_back(s2), group3.push_back(s3);
        int val1 = strhash(s1) + strhash(s2);
        int val2 = strhash(s1) + strhash(s3);
        int val3 = strhash(s2) + strhash(s3);
        if (!groups.count(val1)) {
            vector<vector<string>> gru;
            gru.push_back(group1);
            groups[val1] = gru;
        }
        else groups[val1].push_back(group1);
        if (!groups.count(val2)) {
            vector<vector<string>> gru;
            gru.push_back(group2);
            groups[val2] = gru;
        }
        else groups[val2].push_back(group2);
        if (!groups.count(val3)) {
            vector<vector<string>> gru;
            gru.push_back(group3);
            groups[val3] = gru;
        }
        else groups[val3].push_back(group3);
    }
    for (vector<string>& L : tg) {
        int val = strhash(L[0]) + strhash(L[1]);
        if (!groups.count(val)) res++;
        else {
            vector<vector<string>> group = groups[val];
            bool found = false;
            for (vector<string> L1 : group) {
                if ((L[0] == L1[0] && L[1] == L1[1]) || (L[0] == L1[1] && L[1] == L1[0])) {
                    found = true;
                    break;
                }
            }
            if (!found) res++;
        }
    }
    for (vector<string>& L : apart) {
        int val = strhash(L[0]) + strhash(L[1]);
        if (!groups.count(val)) continue;
        else {
            vector<vector<string>> group = groups[val];
            for (vector<string> L1 : group) {
                if ((L[0] == L1[0] && L[1] == L1[1]) || (L[0] == L1[1] && L[1] == L1[0])) {
                    res++;
                    break;
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}