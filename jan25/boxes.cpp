#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
    int n;
    vector<vector<int>> boxes;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> box;
        int l, w, h;
        cin >> l >> w >> h;
        int area = l*w*h;
        box.push_back(area), box.push_back(l), box.push_back(w), box.push_back(h);
        boxes.push_back(box);
    }
    sort(boxes.begin(), boxes.end());
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, w, h;
        cin >> l >> w >> h;
        bool fits = false;
        for (int j = 0; j < n; j++) {
            vector<int> box = boxes[j];
            if (l <= box[1] && w <= box[2] && h <= box[3]) {
                cout << box[0] << "\n";
                fits = true;
                break;
            }
            if (l <= box[1] && h <= box[2] && w <= box[3]) {
                cout << box[0] << "\n";
                fits = true;
                break;
            }
            if (w <= box[1] && l <= box[2] && h <= box[3]) {
                cout << box[0] << "\n";
                fits = true;
                break;
            }
            if (w <= box[1] && h <= box[2] && l <= box[3]) {
                cout << box[0] << "\n";
                fits = true;
                break;
            }
            if (h <= box[1] && w <= box[2] && l <= box[3]) {
                cout << box[0] << "\n";
                fits = true;
                break;
            }
            if (h <= box[1] && l <= box[2] && w <= box[3]) {
                cout << box[0] << "\n";
                fits = true;
                break;
            }
        }
        if (!fits) cout << "Item does not fit.\n";
    }
    return 0;
}