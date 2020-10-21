#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<pair<int, int> > have;
vector<pair<int, int> > pre;
int n, a, b;

int get(int now) {
    if (pre[now].first != now) {
        pre[now].first = get(pre[now].first);
    }
    return pre[now].first;
}

int main() {
    freopen("dsu.in", "r", stdin);
    freopen("dsu.out", "w", stdout);
    cin >> n;
    have.resize(n);
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        have[i] = make_pair(i + 1, i + 1);
        pre[i] = make_pair(i, 1);
    }
    string s;
    while (cin >> s) {
        if (s[0] == 'u') {
            cin >> a >> b;
            a--; b--;
            a = get(a);
            b = get(b);
            if (pre[a].second < pre[b].second) {
                swap(a, b);
            }
            if (a == b) {
                continue;
            }
            pre[b].first = a;
            pre[a].second += pre[b].second;
            have[a].first = min(have[a].first, have[b].first);
            have[a].second = max(have[a].second, have[b].second);
        } else {
            cin >> a;
            a--;
            a = get(a);
            cout << have[a].first << " " << have[a].second << " " << pre[a].second << endl;
        }
    }
    return 0;
}