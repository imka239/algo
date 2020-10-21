#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

vector<unsigned int> a;
vector<unsigned int> b;
unsigned int n, c, d, m;
long long inv;

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
            inv += rig - (rig + lef) / 2;
            continue;
        }
        if (a[le2] <= a[le3]) {
            b[m] = a[le2];
            le2++;
            inv += le3 - (rig + lef) / 2;
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
    freopen("invcnt.in", "r", stdin);
    freopen("invcnt.out", "w", stdout);
    cin >> n >> m;
    a.resize(n);
    cin >> c >> d;
    unsigned int cur = 0;
    for (unsigned int i = 0; i < n; i++) {
        cur = cur * c + d;
        a[i] = (cur >> 8) % m;
    }
    sorting(0, n);
    cout << inv << endl;
    return 0;
}