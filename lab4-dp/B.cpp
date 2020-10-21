#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int n;
vector<long long> a;
vector<long long> dp;
vector<long long> ind;
vector<long long> ans;
vector<long long> pred;
const long long MA = 1e18;


int main() {
    freopen("lis.in", "r", stdin);
    freopen("lis.out", "w", stdout);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp.resize(n + 5);
    ind.resize(n + 5);
    pred.resize(n + 5);
    dp[0] = -MA;
    ind[0] = -1;
    for (int i = 1; i < n + 4; i++) {
        dp[i] = MA;
        ind[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        int nex = int(upper_bound(dp.begin(), dp.end(), a[i] - 1) - dp.begin());
        dp[nex] = a[i];
        ind[nex] = i;
        pred[i] = ind[nex - 1];
    }
    for (int i = n + 3; i >= 0; i--) {
        if (dp[i] != MA) {
            cout << i << endl;
            long long now = ind[i];
            while (now != -1) {
                ans.push_back(a[now]);
                now = pred[now];
            }
            for (int j = i - 1; j >= 0; j--) {
                cout << ans[j] << " ";
            }
            return 0;
        }
    }
    return 0;
}