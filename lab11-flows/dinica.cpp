#include <bits/stdc++.h>

using namespace std;

struct edge {
    long long capacity;
    long long flow;
    long long price;
    int to;
    edge* obratka;

    edge(): capacity(0), flow(0), price(0), to(0), obratka(nullptr) {}
    edge(long long cap, long long fl, long long pr, int to, edge * obratka)
            : capacity(cap), flow(fl), price(pr), to(to), obratka(obratka) {}
};

const long long MAXIM = 1'000'000'000'000'000'000ll;
int n, m;
vector<vector<edge*> > graph;
vector<long long> p;
vector<int> used;
queue<int> que;
vector<int> height;
vector<int> pos;

int bfs(long long min_flow) {
    while (que.size() != 0) {
        int now = que.front();
        que.pop();
        for (int i = 0; i < (int) graph[now].size(); i++) {
            int next = graph[now][i]->to;
            if (height[next] == 0 && graph[now][i]->capacity - graph[now][i]->flow >= min_flow) {
                height[next] = height[now] + 1;
                que.push(next);
            }
        }
    }
    return 0;
}

long long dfs(int now, long long min_flow, long long min_at_path) {
    used[now] = 1;
    if (now == n - 1) {
        return min_at_path;
    }
    for (; pos[now] < (int) graph[now].size(); pos[now]++) {
        int next = graph[now][pos[now]]->to;
        if (height[now] == height[next] - 1) {
            if (graph[now][pos[now]]->capacity - graph[now][pos[now]]->flow >= min_flow
                && used[next] == 0) {
                long long x = dfs(next, min_flow, min(min_at_path,
                                                      graph[now][pos[now]]->capacity - graph[now][pos[now]]->flow));
                if (x > 0) {
                    graph[now][pos[now]]->flow += x;
                    graph[now][pos[now]]->obratka->flow -= x;
                    return x;
                }
            }
        }
    }
    return 0;
}

void more_oil_for_the_god_of_oil() {
    long long c = 536870912;
    while (c > 0) {
        while (true) {
            fill(height.begin(), height.end(), 0);
            height[0] = 1;
            que.push(0);
            bfs(c);
            if (height[n - 1] == 0) {
                break;
            }
            fill(pos.begin(), pos.end(), 0);
            while (true) {
                fill(used.begin(), used.end(), false);
                if (dfs(0, c, 1e9) == 0) {
                    break;
                }
            }
        }
        c /= 2;
    }
    long long ans = 0;
    for (auto i : graph[n - 1]) {
        ans -= i->flow;
    }
    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    graph.resize(n);
    used.resize(n);
    pos.resize(n);
    height.resize(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge* edge1 = new edge(c, 0, 0, b - 1, nullptr);
        edge* edge2 = new edge(0, 0, 0, a - 1, nullptr);
        edge1->obratka = edge2;
        edge2->obratka = edge1;
        graph[a - 1].push_back(edge1);
        graph[b - 1].push_back(edge2);
    }
    more_oil_for_the_god_of_oil();
    return 0;
}