#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int n, k, a, b, c, fi, se;
vector<int> mas;

int main() {
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    k--;
    mas.resize(n + 5);
    cin >> a >> b >> c >> fi >> se;
    mas[0] = fi;
    mas[1] = se;
    for (int i = 2; i < n; i++) {
        mas[i] = a * mas[i - 2] + b * mas[i - 1] + c;
    }
    int l = 0;
    int r = n;
    while (true) {
        int x = mas[(l + r) / 2];
        vector<int> another_mas;
        another_mas.resize(r - l);
        int lef = l;
        int rig = r;
        for (int i = l; i < r; i++) {
            if (mas[i] == x) {
                continue;
            }
            if (mas[i] < x) {
                another_mas[lef - l] = mas[i];
                lef++;
            } else {
                another_mas[rig - 1 - l] = mas[i];
                rig--;
            }
        }
        for (int i = l; i < r; i++) {
            mas[i] = another_mas[i - l];
        }
        if (lef <= k && rig > k) {
            cout << x << endl;
            return 0;
        }
        if (rig <= k) {
            l = rig;
        } else {
            r = lef;
        }
    }
}