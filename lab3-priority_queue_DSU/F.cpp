#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<pair<int, pair<int, int> > > have;
vector<pair<int, int> > pre;
vector<string> ans;
int n, m, k, c, a, b;

int get(int now) {
    if (pre[now].first != now) {
        pre[now].first = get(pre[now].first);
    }
    return pre[now].first;
}

int main() {
    freopen("cutting.in", "r", stdin);
    freopen("cutting.out", "w", stdout);
    cin >> n >> m >> k;
    pre.resize(n);
    have.resize(k);
    for (int i = 0; i < m; i++) {
        cin >> b >> c;
    }
    for (int i = 0; i < n; i++) {
        pre[i] = make_pair(i, 1);
    }
    string s;
    for (int i = 0; i < k; i++) {
        cin >> s;
        cin >> a >> b;
        have[k - i - 1].second = make_pair(a - 1, b - 1);
        if (s[0] == 'a') {
            have[k - i - 1].first = 2;
        } else {
            have[k - i - 1].first = 1;
        }
    }
    for (int i = 0; i < k; i++) {
        if (have[i].first == 1) {
            a = have[i].second.first;
            b = have[i].second.second;
            a = get(a);
            b = get(b);
            if (pre[a].second < pre[b].second) {
                swap(a, b);
            }
            if (a == b) {
                continue;
            }
            pre[b].first = a;
        } else {
            a = have[i].second.first;
            b = have[i].second.second;
            a = get(a);
            b = get(b);
            if (a == b) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
        }
    }
    for (unsigned int i = 0; i < ans.size(); i++) {
        cout << ans[ans.size() - 1 - i] << endl;
    }
    return 0;
}