#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int n;
vector<pair<long long, long long> > a;
vector<vector<long long> > dp;

void lets_find_ans(int l, int range) {
    if (range == 1) {
        cout << "A";
        return;
    }
    if (range == 0) {
        return;
    }
    for (int h = 1; h < range; h++) {
        if (dp[l][range] == dp[l][h] + dp[l + h][range - h]
                            + a[l].first * a[l + h].first * a[l + range - 1].second) {
            if (h != 1) {
                cout << "(";
            }
            lets_find_ans(l, h);
            if (h != 1) {
                cout << ")";
            }
            if (range - h != 1) {
                cout << "(";
            }
            lets_find_ans(l + h, range - h);
            if (range - h != 1) {
                cout << ")";
            }
            return;
        }
    }
}

int main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    dp.resize(n + 5);
    for (int i = 0; i < n; i++) {
        dp[i].resize(n + 5);
        dp[i][0] = 0;
        dp[i][1] = 0;
        for (int j = 2; j <= n; j++) {
            dp[i][j] = 1e18;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j <= n) {
                for (int h = 1; h < i; h++) {
                    dp[j][i] = min(dp[j][i], dp[j][h] + dp[j + h][i - h] +
                                             a[j].first * a[j + h].first * a[j + i - 1].second);
                }
            }
        }
    }
    if (n != 1) {
        cout << "(";
    }
    lets_find_ans(0, n);
    if (n != 1) {
        cout << ")";
    }
    return 0;
}