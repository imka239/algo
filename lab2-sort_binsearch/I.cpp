#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> a;
vector<vector<long long> > cash;
int n, m, c, p;
vector<long long> b;

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
    freopen("supermarket.in", "r", stdin);
    freopen("supermarket.out", "w", stdout);
    cin >> m;
    cash.resize(m);
    a.resize(m);
    for (int i = 0; i < m; i++) {
        cash[i].resize(3);
        cin >> cash[i][0] >> cash[i][1] >> cash[i][2];
    }
    cin >> n >> p;
    long long l = -1;
    long long r = cash[0][0] * p + cash[0][1] + cash[0][2] + 1;
    while (l < r - 1) {
        long long mid = (l + r) / 2;
        for (int i = 0; i < m; i++) {
            if (cash[i][0] == 0) {
                a[i] = p;
                continue;
            }
            a[i] = max(0ll, (mid - cash[i][1] - cash[i][2]) / cash[i][0]);
        }
        sorting(0, m);
        long long su = 0;
        for (int i = m - 1; i >= 0; i--) {
            if (m - 1 - i + 1 > n) {
                break;
            }
            su += a[i];
        }
        if (su >= p) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    return 0;
}