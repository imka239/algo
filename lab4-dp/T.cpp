#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

long long n, a, b;
string s;
vector<vector<pair<long long, int> > > graph;
vector<pair<long long, long long> > dp;
vector<pair<long long, long long> > dp_down;
vector<long long> ans;

void lets_go(long long now, long long pred) {
    dp[now].first++;
    for (int i = 0; i < (int) graph[now].size(); i++) {
        long long nex = graph[now][i].first;
        if (nex != pred) {
            lets_go(nex, now);
            dp[now].first += dp[nex].first;
            dp[now].second += dp[nex].first + dp[nex].second;
        }
    }
}

void check(long long now, long long pred) {
    for (int i = 0; i < (int) graph[now].size(); i++) {
        long long nex = graph[now][i].first;
        if (nex != pred) {
            check(nex, now);
            ans[graph[now][i].second] = dp[nex].first * dp_down[nex].second
                                        + dp[nex].second * dp_down[nex].first;
        }
    }
}

void lets_find(long long now, long long pred) {
    if (pred != -1ll) {
        dp_down[now].first += dp[pred].first
                              - dp[now].first + dp_down[pred].first;
        dp_down[now].second += dp[pred].second
                               - dp[now].second - dp[now].first + dp_down[pred].second
                               + dp_down[now].first;
    }
    for (int i = 0; i < (int) graph[now].size(); i++) {
        long long nex = graph[now][i].first;
        if (nex != pred) {
            lets_find(nex, now);
        }
    }
}

int main() {
    freopen("treedp.in", "r", stdin);
    freopen("treedp.out", "w", stdout);
    cin >> n;
    dp.resize(n);
    dp_down.resize(n);
    graph.resize(n);
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(make_pair(b, i));
        graph[b].push_back(make_pair(a, i));
    }
    lets_go(0ll, -1);
    lets_find(0ll, -1);
    ans.resize(n - 1);
    check(0ll, -1l);
    for (int i = 0; i < n - 1; i++) {
        cout << ans[i] << endl;;
    }
    return 0;
}