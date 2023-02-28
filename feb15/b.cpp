#include <bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;

ll res = 0;

void dfs(vector<vector<int>>& tree, vector<ll>& weights, vector<int>& dfslist, vector<bool>& visit, int cur) {
    dfslist.push_back(cur);
    if (visit[cur]) return;
    visit[cur] = true;
    int n = dfslist.size();
    if (n >= 3) {
        for (int i : dfslist) cout << i << " ";
        cout << endl;
        ll add = (ll)(2*(weights[cur]*weights[dfslist[n-3]]));
        cout << add << endl;
        res += add;
    }
    for (int v : tree[cur]) dfs(tree, weights, dfslist, visit, v);
}

int main() {
    int n, v, w, x;
    ll mod = 10007;
    cin >> n;
    vector<vector<int>> tree(n);
    vector<ll> weights;
    for (int i = 0; i < n-1; i++) {
        cin >> v >> w;
        tree[v-1].push_back(w-1);
        tree[w-1].push_back(v-1);
    }
    for (int i = 0; i < n; i++) {
        cin >> x;
        weights.push_back((ll)x);
    }
    vector<int> dfslist;
    vector<bool> visit(n, false);
    dfs(tree, weights, dfslist, visit, 0);
    cout << res % mod << endl;
    return 0;
}