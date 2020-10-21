#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>

using namespace std;

int n;
vector<int> a;
vector<vector<long long> > dp;
vector<vector<int> > razrez;
vector<int> ans;
vector<long long> su;

void find_ans(int nowx, int nowy) {
    if (nowx == nowy) {
        for (unsigned int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
        cout << endl;
    }
    for (int k = nowx; k < nowy; k++) {
        if (dp[nowx][nowy] == dp[nowx][k] + dp[k + 1][nowy] + su[nowy + 1] - su[nowx]) {
            ans.push_back(0);
            find_ans(nowx, k);
            ans[ans.size() - 1] = 1;
            find_ans(k + 1, nowy);
            ans.pop_back();
            break;
        }
    }
}

int main() {
    freopen("optimalcode.in", "r", stdin);
    freopen("optimalcode.out", "w", stdout);
    cin >> n;
    a.resize(n);
    dp.resize(n);
    razrez.resize(n);
    su.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        su[i + 1] = su[i] + a[i];
        dp[i].resize(n);
        razrez[i].resize(n);
        for (int j = 0; j < n; j++) {
            dp[i][j] = 1e18;
        }
        dp[i][i] = 0;
        razrez[i][i] = i;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j >= n) {
                break;
            }
            int nex = i + j;
            for (int k = razrez[j][nex - 1]; k <= razrez[j + 1][nex]; k++) {
                if (k + 1 > nex) {
                    continue;
                }
                if (dp[j][nex] > dp[j][k] + dp[k + 1][nex] + su[nex + 1] - su[j]) {
                    razrez[j][nex] = k;
                }
                dp[j][nex] = min(dp[j][nex],
                                 dp[j][k] + dp[k + 1][nex] + su[nex + 1] - su[j]);
            }
        }
    }
    cout << dp[0][n - 1] << endl;
    find_ans(0, n - 1);
    return 0;
}