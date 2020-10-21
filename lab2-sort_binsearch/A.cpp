#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

vector<int> a;
vector<int> b;
int n;

void sorting(int lef, int rig) {
    if (rig == lef + 1) {
        return;
    }
    sorting(lef, (rig + lef) / 2);
    sorting((rig + lef) / 2, rig);
    int le2 = lef;
    b.resize(rig - lef);
    int m = 0;
    int le3 = (rig + lef) / 2;
    while (le2 < (rig + lef) / 2 || le3 < rig) {
        if (le2 == (rig + lef) / 2) {
            b[m] = a[le3];
            le3++;
            m++;
            continue;
        }
        if (le3 == rig) {
            b[m] = a[le2];
            le2++;
            m++;
            continue;
        }
        if (a[le2] < a[le3]) {
            b[m] = a[le2];
            le2++;
            m++;
        } else {
            b[m] = a[le3];
            le3++;
            m++;
        }
    }
    for (int i = 0; i < rig - lef; i++) {
        a[lef + i] = b[i];
    }
}

int main() {
    freopen("sort.in", "r", stdin);
    freopen("sort.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sorting(0, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}