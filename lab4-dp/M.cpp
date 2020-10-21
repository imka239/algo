#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

vector<vector<long long> > dp;
vector<vector<pair<int, long long> > > graph;
int a, b, n, m;
long long c, ans;
const long long MA = 1e18;


int main() {
    freopen("salesman.in", "r", stdin);
    freopen("salesman.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    graph.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    ans = MA;
    dp.resize((1 << n));
    for (int j = 0; j < (1 << n); j++) {
        dp[j].resize(n);
        for (int h = 0; h < n; h++) {
            dp[j][h] = MA;
        }
    }
    for (int i = 0; i < n; i++) {
        int now = (1 << i);
        dp[now][i] = 0;
    }
    for (int j = 1; j < (1 << n); j++) {
        for (int h = 0; h < n; h++) {
            if ((j & (1 << h)) == 0) {
                continue;
            }
            int nex = j ^ (1 << h);
            for (unsigned int kek = 0; kek < graph[h].size(); kek++) {
                int kek1 = graph[h][kek].first;
                if (((1 << kek1) & nex) == 0) {
                    continue;
                }
                long long kek2 = graph[h][kek].second;
                if (dp[nex][kek1] != MA) {
                    dp[j][h] = min(dp[j][h], dp[nex][kek1] + kek2);
                }
            }
        }
    }
    for (int h = 0; h < n; h++) {
        if (dp[(1 << n) - 1][h] != MA) {
            ans = min(ans, dp[(1 << n) - 1][h]);
        }
    }
    if (ans == MA) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}