#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long double> v;
vector<long double> w;
vector<long double> a;
vector<pair<long double, int> > a1;
int n, k;
long double ans1, ans2;
const long double eps = 0.00001;

vector<long double> b;
vector<pair<long double, int>> b1;

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

void sorting1(int lef, int rig) {
    if (rig == lef + 1) {
        return;
    }
    sorting1(lef, (rig + lef) / 2);
    sorting1((rig + lef) / 2, rig);
    int le2 = lef;
    b1.resize(rig - lef);
    int m = 0;
    int le3 = (rig + lef) / 2;
    while (le2 < (rig + lef) / 2 || le3 < rig) {
        if (le2 == (rig + lef) / 2) {
            b1[m] = a1[le3];
            le3++;
            m++;
            continue;
        }
        if (le3 == rig) {
            b1[m] = a1[le2];
            le2++;
            m++;
            continue;
        }
        if (a1[le2] < a1[le3]) {
            b1[m] = a1[le2];
            le2++;
            m++;
        } else {
            b1[m] = a1[le3];
            le3++;
            m++;
        }
    }
    for (int i = 0; i < rig - lef; i++) {
        a1[lef + i] = b1[i];
    }
}



int main() {
    freopen("kbest.in", "r", stdin);
    freopen("kbest.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    v.resize(n);
    w.resize(n);
    a.resize(n);
    a1.resize(n);
    ans1 = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i] >> w[i];
        if (i < k) {
            ans1 = max(ans1, v[i] / w[i]);
        }
    }
    long double l = -0.0001;
    long double r = ans1 + 1;
    while (r - l > eps) {
        long double mid = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            a[i] = v[i] - mid * w[i];
        }
        sorting(0, n);
        long double answ = 0;
        for (int i = n - 1; i >= n - k; i--) {
            answ += a[i];
        }
        if (answ >= -eps) {
            l = mid;
        } else {
            r = mid;
        }
    }
    for (int i = 0; i < n; i++) {
        a1[i].first = v[i] - r * w[i];
        a1[i].second = i;
    }
    sorting1(0, n);
    for (int i = n - 1; i >= n - k; i--) {
        cout << a1[i].second + 1 << " ";
    }
    return 0;
}