#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

vector<vector<long long> > dp;
long long a, b, n, m, l;
const long long MA = 1e18;

long long check(long long min_size) {
    dp.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i].resize(m + 1);
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int h = 0; h <= i; h++) {
                long long an = max(0ll, (min_size - h * a) / b);
                while (h * a + an * b < min_size) {
                    an++;
                }
                if (an <= j) {
                    dp[i][j] = max(dp[i][j], dp[i - h][j - an] + 1);
                }
            }
        }
    }
    return dp[n][m];
}

int main() {
    freopen("bridge.in", "r", stdin);
    freopen("bridge.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> m >> b >> l;
    long long lef = 0;
    long long righ = n * a + m * b + 1;
    while (lef < righ - 1) {
        long long mid = (lef + righ) / 2;
        long long kek = check(mid);
        if (kek >= l) {
            lef = mid;
        } else {
            righ = mid;
        }
    }
    cout << lef << endl;
    return 0;
}