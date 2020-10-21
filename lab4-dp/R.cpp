#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>

using namespace std;

int n;
vector<vector<int> > dp;
vector<vector<int> > perex;
vector<vector<pair<int, int> > > pred;
vector<vector<int> > used;
queue<pair<int, int> > bfs;
vector<int> ans;

int main() {
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    cin >> n;
    if (n < 10) {
        cout << n << endl;
        return 0;
    }
    dp.resize(n + 1);
    pred.resize(n + 1);
    perex.resize(n + 1);
    used.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i].resize(n);
        pred[i].resize(n);
        perex[i].resize(n);
        used[i].resize(n);
    }
    for (int i = 1; i < 10; i++) {
        dp[i][i] = 1;
        bfs.push(make_pair(i, i));
        pred[i][i] = make_pair(-1, -1);
        perex[i][i] = i;
        used[i][i] = 1;
    }
    while (bfs.size() != 0) {
        pair<int, int> nex = bfs.front();
        bfs.pop();
        for (int i = 0; i < 10; i++) {
            if (nex.first + i > n) {
                continue;
            }
            int lol = (nex.second * 10 + i) % n;
            int l = nex.first + i;
            if (used[l][lol] == 0) {
                dp[l][lol] =
                        dp[nex.first][nex.second] + 1;
                pred[l][lol] = make_pair(nex.first, nex.second);
                perex[l][lol] = i;
            }
            if (used[l][lol] == 0) {
                bfs.push(make_pair(l, lol));
                used[l][lol] = 1;
            }
            if (dp[l][lol] >
                dp[nex.first][nex.second] + 1) {
                dp[l][lol] =
                        dp[nex.first][nex.second] + 1;
                pred[l][lol] = make_pair(nex.first, nex.second);
                perex[l][lol] = i;
            }
        }
    }
    int nowx = n;
    int nowy = 0;
    while (nowx > 0 || nowy > 0) {
        ans.push_back(perex[nowx][nowy]);
        int z = pred[nowx][nowy].first;
        nowy = pred[nowx][nowy].second;
        nowx = z;
    }
    reverse(ans.begin(), ans.end());
    for (unsigned int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }
    return 0;
}