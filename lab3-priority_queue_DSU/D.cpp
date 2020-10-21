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
    freopen("parking.in", "r", stdin);
    freopen("parking.out", "w", stdout);
    cin >> n;
    have.resize(n);
    pre.resize(n);
    for (int i = 0; i < n; i++) {
        pre[i] = make_pair(i, 1);
    }
    for (int i = 0; i < n; i++) {
        cin >> a;
        a--;
        a = get(a);
        cout << a + 1 << " ";
        b = get((a + 1) % n);
        pre[a].first = b;
    }
    return 0;
}