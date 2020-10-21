#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

long long n, m, k;
vector<vector<long long> > dp;
vector<vector<long long> > nums;
vector<long long> ans;
vector<long long> used;
vector<long long> a;
const long long MA = 1e18;

long long gcd(long long b, long long c) {
    if (c % b == 0) {
        return b;
    }
    return gcd(c % b, b);
}

int main() {
    freopen("perm.in", "r", stdin);
    freopen("perm.out", "w", stdout);
    cin >> n >> m >> k;
    dp.resize((1 << n));
    a.resize(n);
    used.resize(n);
    nums.resize(n);
    long long mask = 0;
    for (int i = 0; i < (1 << n); i++) {
        dp[i].resize(n);
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[1 << i][i] = 1;
        mask += (1 << i);
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        nums[i].resize(n);
        for (int j = 0; j < n; j++) {
            nums[i][j] = gcd(a[i], a[j]);
            if (i == j) {
                nums[i][j] = MA;
            }
        }
    }
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                for (int h = 0; h < n; h++) {
                    if ((i & (1 << h)) != 0 && j != h && nums[j][h] >= k) {
                        dp[i][j] += dp[i ^ (1 << j)][h];
                    }
                }
            }
        }
    }
    int now = 0;
    while (now != n) {
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (used[i] == 0 && (now == 0 || nums[i][ans[now - 1]] >= k)) {
                if (dp[mask][i] < m) {
                    m -= dp[mask][i];
                } else {
                    mask = (mask ^ (1 << i));
                    used[i] = 1;
                    ans.push_back(i);
                    now++;
                    flag = 1;
                    break;
                }
            }
        }
        if (flag == 0) {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[ans[i]] << " ";
    }
    return 0;
}