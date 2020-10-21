#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

long long n, m, k;
vector<vector<long long> > dp;
const int MA = 1e9;

int main() {
    freopen("levenshtein.in", "r", stdin);
    freopen("levenshtein.out", "w", stdout);
    string s1, s2;
    cin >> s1 >> s2;
    n = s1.size();
    m = s2.size();
    dp.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        dp[i].resize(m + 1);
        for (int j = 0; j <= m; j++) {
            dp[i][j] = MA;
            if (i == 0) {
                if (j == 0) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1 + dp[i][j - 1];
                }
            } else {
                if (j == 0) {
                    dp[i][j] = dp[i - 1][j] + 1;
                } else {
                    dp[i][j] = dp[i][j - 1] + 1;
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
                    if (s1[i - 1] == s2[j - 1]) {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
                    } else {
                        dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 1);
                    }
                }
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}