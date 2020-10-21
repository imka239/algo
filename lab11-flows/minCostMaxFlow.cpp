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

bool bellman() {
    vector<long long> dist;
    vector<edge*> pred;
    dist.resize(n);
    pred.resize(n);
    fill(dist.begin(), dist.end(), MAXIM);
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto k : graph[j]) {
                if (dist[j] < MAXIM && k->capacity - k->flow > 0
                    && dist[k->to] > dist[j] + k->price) {
                    dist[k->to] = dist[j] + k->price;
                    pred[k->to] = k->obratka;
                }
            }
        }
    }
    if (dist[n - 1] < MAXIM) {
        int now = n - 1;
        edge* pre = pred[n - 1];
        long long max_flow = MAXIM;
        while (now != 0) {
            max_flow = min(max_flow, pre->obratka->capacity - pre->obratka->flow);
            now = pre->to;
            pre = pred[pre->to];
        }
        now = n - 1;
        pre = pred[n - 1];
        while (now != 0) {
            pre->flow -= max_flow;
            pre->obratka->flow += max_flow;
            now = pre->to;
            pre = pred[pre->to];
        }
        for (int i = 0; i < n; i++) {
            p[i] = dist[i];
        }
        return true;
    }
    return false;
}

bool dijkstra() {
    vector<long long> dist;
    vector<edge*> pred;
    vector<int> used;
    dist.resize(n);
    pred.resize(n, nullptr);
    used.resize(n);
    fill(dist.begin(), dist.end(), MAXIM);
    fill(used.begin(), used.end(), 0);
    dist[0] = 0;
    for (int i = 0; i < n; i++) {
        int ans = -1;
        for (int j = 0; j < n; j++) {
            if (used[j] == 0) {
                if (ans == -1 || dist[ans] > dist[j]) {
                    ans = j;
                }
            }
        }
        used[ans] = 1;
        if (dist[ans] != MAXIM) {
            for (auto j : graph[ans]) {
                if (j->capacity - j->flow > 0) {
                    if (dist[j->to] > dist[ans] + j->price + p[ans] - p[j->to]) {
                        dist[j->to] = dist[ans] + j->price + p[ans] - p[j->to];
                        pred[j->to] = j->obratka;
                    }
                }
            }
        }
    }
    if (dist[n - 1] < MAXIM) {
        for (int i = 0; i < n; i++) {
            p[i] += dist[i];
        }
        int now = n - 1;
        edge* pre = pred[n - 1];
        long long max_flow = MAXIM;
        while (now != 0) {
            max_flow = min(max_flow, pre->obratka->capacity - pre->obratka->flow);
            now = pre->to;
            pre = pred[pre->to];
        }
        now = n - 1;
        pre = pred[n - 1];
        while (now != 0) {
            pre->flow -= max_flow;
            pre->obratka->flow += max_flow;
            now = pre->to;
            pre = pred[pre->to];
        }
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    graph.resize(n);
    p.resize(n);
    for (int i = 1; i <= m; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        edge* edge1 = new edge(c, 0, d, b - 1, nullptr);
        edge* edge2 = new edge(0, 0, -d, a - 1, nullptr);
        edge1->obratka = edge2;
        edge2->obratka = edge1;
        graph[a - 1].push_back(edge1);
        graph[b - 1].push_back(edge2);
    }

    bool flag = bellman();
    while (flag) {
        flag = dijkstra();
    }
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (auto j : graph[i]) {
            if (j->flow > 0) {
                ans += j->price * j->flow;
            }
        }
    }
    cout << ans << endl;
    return 0;
}