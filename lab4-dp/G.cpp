#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

int n, m, k;
vector<long long> dp;
vector<long long> maxim;
vector<long long> answer;
vector<int> a;
vector<int> b;
vector<int> c;
const int MA = 1e9;
long long ans;


int main() {
    freopen("meetings.in", "r", stdin);
    freopen("meetings.out", "w", stdout);
    cin >> n >> k;
    a.resize(n);
    b.resize(n);
    c.resize(n);
    dp.resize(1 << (n + 1));
    maxim.resize(1 << (n + 1));
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[0] = k;
    maxim[0] = 0;
    for (int i = 1; i < (1 << (n + 1)); i++) {
        dp[i] = MA;
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0) {
                maxim[i] = maxim[(i ^ (1 << j))] + 1;
            }
            if ((i & (1 << j)) != 0 && dp[(i ^ (1 << j))] != MA) {
                if (dp[(i ^ (1 << j))] >= a[j] && dp[(i ^ (1 << j))] <= b[j]) {
                    dp[i] = dp[(i ^ (1 << j))] + c[j];
                    if (maxim[i] > maxim[ans]) {
                        ans = i;
                    }
                    break;
                }
            }
        }
    }
    cout << maxim[ans] << endl;
    long long i = ans;
    while (i != 0) {
        for (int j = 0; j < n; j++) {
            if ((i & (1 << j)) != 0 && dp[(i ^ (1 << j))] != MA) {
                if (dp[(i ^ (1 << j))] >= a[j] && dp[(i ^ (1 << j))] <= b[j]
                    && dp[i] == dp[(i ^ (1 << j))] + c[j]) {
                    i = i ^ (1 << j);
                    answer.push_back(j);
                    break;
                }
            }
        }
    }
    reverse(answer.begin(), answer.end());
    for (int j = 0; j < maxim[ans]; j++) {
        cout << answer[j] + 1 << " ";
    }
    return 0;
}