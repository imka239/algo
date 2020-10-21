#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

vector<pair<long long, long long> > dp;
vector<vector<pair<int, long long> > > graph;
vector<vector<pair<int, long long> > > gra;
vector<int> used;
int a, b, n, m;
long long c, ans;
const long long MA = 1e18;

void findSt(int now, int pred) {
    for (unsigned int i = 0; i < gra[now].size(); i++) {
        if (gra[now][i].first == pred) {
            continue;
        }
        graph[now].push_back(gra[now][i]);
        findSt(gra[now][i].first, now);
    }
}

void dfs(int now) {
    for (unsigned int i = 0; i < graph[now].size(); i++) {
        dfs(graph[now][i].first);
    }
    for (unsigned int i = 0; i < graph[now].size(); i++) {
        dp[now].first += max(dp[graph[now][i].first].first, dp[graph[now][i].first].second);
    }
    ans = dp[now].first;
    for (unsigned int i = 0; i < graph[now].size(); i++) {
        dp[now].second = max(dp[now].second, ans -
                                             max(dp[graph[now][i].first].first, dp[graph[now][i].first].second)
                                             + dp[graph[now][i].first].first + graph[now][i].second);
    }
}

int main() {
    freopen("matching.in", "r", stdin);
    freopen("matching.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    graph.resize(n);
    gra.resize(n);
    used.resize(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        used[b] = 1;
        gra[a].push_back(make_pair(b, c));
        gra[b].push_back(make_pair(a, c));
    }
    findSt(0, -1);
    dp.resize(n);
    dfs(0);
    cout << max(dp[0].first, dp[0].second);
    return 0;
}