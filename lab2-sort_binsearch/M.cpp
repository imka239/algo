#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> ans;
vector<pair<long long, long long> > path;
long long n, m, k, a, b, c;

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> c;
        for (int j = 0; j < c; j++) {
            cin >> a >> b;
            if (a > b) {
                swap(a, b);
            }
            path.push_back(make_pair(a - 1, b - 1));
        }
    }
    for (int i = 0; i < (1 << (n + 1)); i++) {
        int nex = i;
        for (int j = 0; j < m; j++) {
            if (((1 << path[j].first) & nex) > 0 && ((1 << path[j].second) & nex) == 0) {
                nex = nex ^ (1 << path[j].first);
                nex = nex ^ (1 << path[j].second);
            }
        }
        int fl = 0;
        for (int i = 0; i < n; i++) {
            if ((nex & (1 << i)) > 0) {
                fl = 1;
            } else {
                if (fl == 1) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}