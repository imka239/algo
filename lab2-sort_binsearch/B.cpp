#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

int n, m, b;
vector<int> a;

int bin1(int lef, int rig, int val) {
    while (rig > lef + 1) {
        int mid = (rig + lef) / 2;
        if (a[mid] >= val) {
            rig = mid;
        } else {
            lef = mid;
        }
    }
    if (rig == n || a[rig] != val) {
        return -1;
    }
    return rig + 1;
}

int bin2(int lef, int rig, int val) {
    while (rig > lef + 1) {
        int mid = (rig + lef) / 2;
        if (a[mid] > val) {
            rig = mid;
        } else {
            lef = mid;
        }
    }
    if (lef == -1 || a[lef] != val) {
        return -1;
    }
    return lef + 1;
}

int main() {
    freopen("binsearch.in", "r", stdin);
    freopen("binsearch.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> b;
        cout << bin1(-1, n, b) << " ";
        cout << bin2(-1, n, b) << endl;
    }
    return 0;
}