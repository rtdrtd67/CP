#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int n;
void prim(vector<vector<pair<int, int>>> graph, set<pair<int, int>>& edgeset, set<pair<int, int>>& curtree) {
    priority_queue<vector<int>> edges;
    // vector<vector<pair<int, int>> tree;
    int cur = 1;
    int count = 0;
    while (count < n-1) {
        for (pair<int, int> p : graph[cur]) {
            vector<int> edge(4);
            pair<int, int> p2;
            edge[0] = -p.first;
            edge[2] = cur;
            edge[3] = p.second;
            p2.first = cur;
            p2.second = p.second;
            if (curtree.count(p2)) edge[1] = 1;
            else edge[1] = 0;
            if (!edgeset.count(p2)) edges.push(edge);
        }
        vector<int> minedge = edges.top();
        edges.pop();
        // pair<int, int> p1(minedge.first, minedge.second.first);
        // pair<int, int> p2(minedge.first, minedge.second.second);
        // tree[minedge.second.first].push_back(p2);
        // tree[minedge.second.second].push_back(p1);
        pair<int, int> e1(minedge[2], minedge[3]);
        pair<int, int> e2(minedge[3], minedge[2]);
        edgeset.insert(e1);
        edgeset.insert(e2);
        cur = minedge[3];
        count++;
    }
}

int main() {
    int m, d;
    cin >> n >> m >> d;
    vector<pair<int, int>> empty;
    vector<vector<pair<int, int>>> graph(n+1, empty);
    set<pair<int, int>> curtree;
    for (int i = 0; i < m; i++) {
        pair<int, int> p1, p2, e1, e2;
        int v, w, c;
        cin >> v >> w >> c;
        p1.second = v, p2.second = w;
        p1.first = c, p2.first = c;
        graph[v].push_back(p2);
        graph[w].push_back(p1);
        e1.first = v, e1.second = w, e2.first = w, e2.second = v;
        if (i < n-1) {
            curtree.insert(e1), curtree.insert(e2);
        }
    }
    int days = 0;
    set<pair<int, int>> edgeset;
    prim(graph, edgeset, curtree);
    // for (pair<int, int> p : edgeset) {
    //     cout << p.first << " " << p.second << "\n";
    // }
    for (pair<int, int> p : curtree) {
        if (!edgeset.count(p)) days++;
    }
    cout << days/2;
    return 0;
}