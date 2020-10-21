#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

vector<vector<long long> > dp;
vector<long long> a;
long long b, n, m, l;
const long long MA = 1e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n);
    dp.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i].resize(n + 1);
        dp[i][1] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            if (i + j <= n) {
                dp[j][i] = (dp[j][i - 1] + dp[j + 1][i - 1] + MA - dp[j + 1][i - 2]) % MA;
                if (a[j] == a[i + j - 1]) {
                    dp[j][i] = (dp[j][i] + dp[j + 1][i - 2] + 1) % MA;
                }
            }
        }
    }
    cout << dp[0][n] << endl;
    return 0;
}