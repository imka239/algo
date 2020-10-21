#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int n, m;
vector<vector<int> > dp;
vector<int> a;
vector<int> c;
vector<int> ans;
const int MA = 1e9;


int main() {
    freopen("knapsack.in", "r", stdin);
    freopen("knapsack.out", "w", stdout);
    cin >> n >> m;
    dp.resize(n + 1);
    a.resize(n);
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for (int i = 0; i <= n; i++) {
        dp[i].resize(m + 1);
        if (i != 0) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = -MA;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j >= a[i - 1]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i - 1]] + c[i - 1]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    int now_1 = n;
    int now_2 = m;
    while (dp[now_1][now_2] != 0) {
        if (dp[now_1][now_2] == dp[now_1 - 1][now_2]) {
            now_1--;
        } else {
            ans.push_back(now_1);
            now_2 -= a[now_1 - 1];
            now_1--;
        }
    }
    cout << ans.size() << endl;
    for (int i = (int)ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    return 0;
}