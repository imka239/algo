#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<long long> mas;
vector<long long> used;
vector<pair<long long, long long> > mini_set;
vector<pair<pair<long long, long long>, pair<long long, long long> > > otr;
long long n, m, a, b, c, now, minim;

void pop_up(long long now) {
    if (now == 0) {
        return;
    }
    if (mini_set[(now - 1) / 2].first > mini_set[now].first) {
        swap(mini_set[(now - 1) / 2], mini_set[now]);
        pop_up((now - 1) / 2);
    }
}

void pop_down(unsigned int now) {
    if (2 * now + 1 >= mini_set.size()) {
        return;
    }
    if (2 * now + 2 < mini_set.size()) {
        if (mini_set[2 * now + 1].first < mini_set[2 * now + 2].first) {
            if (mini_set[2 * now + 1].first < mini_set[now].first) {
                swap(mini_set[2 * now + 1], mini_set[now]);
                pop_down(2 * now + 1);
            }
        } else {
            if (mini_set[2 * now + 2].first < mini_set[now].first) {
                swap(mini_set[2 * now + 2], mini_set[now]);
                pop_down(2 * now + 2);
            }
        }
    } else {
        if (mini_set[2 * now + 1].first < mini_set[now].first) {
            swap(mini_set[2 * now + 1], mini_set[now]);
            pop_down(2 * now + 1);
        }
    }
    return;
}

void check() {
    pair<long long, long long> mini = mini_set[0];
    while (used[mini.second] == 0) {
        swap(mini_set[0], mini_set[mini_set.size() - 1]);
        mini_set.pop_back();
        pop_down(0);
        mini = mini_set[0];
    }
}

int main() {
    freopen("rmq.in", "r", stdin);
    freopen("rmq.out", "w", stdout);
    cin >> n >> m;
    mas.resize(n);
    used.resize(m + 1);
    for (int i = 0; i < n; i++) {
        mas[i] = -((1ll << 31));
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        otr.push_back(make_pair(make_pair(a - 1, 0), make_pair(c, i + 1)));
        otr.push_back(make_pair(make_pair(b - 1, 1), make_pair(c, i + 1)));
    }
    used[0] = 1;
    mini_set.push_back(make_pair((1ll << 31), 0));
    sort(otr.begin(), otr.end());
    now = 0;
    for (int i = 0; i < 2 * m; i++) {
        check();
        minim = -mini_set[0].first;
        for (long long j = now; j < otr[i].first.first; j++) {
            mas[j] = minim;
        }
        long long value = -otr[i].second.first;
        long long ind = otr[i].second.second;
        if (otr[i].first.second == 0) {
            mini_set.push_back(make_pair(value, ind));
            used[ind] = 1;
            pop_up(mini_set.size() - 1);
            check();
            mas[otr[i].first.first] = max(mas[otr[i].first.first], -mini_set[0].first);
        } else {
            check();
            mas[otr[i].first.first] = max(mas[otr[i].first.first], -mini_set[0].first);
            used[ind] = 0;
        }
        now = otr[i].first.first + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << mas[i] << " ";
    }
    cout << endl;
    return 0;
}
/*
3 3
2 2 -500
1 2 -760
1 3 -1000
*/