#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

long long n, m, k;
vector<long long> dp1;
vector<long long> dp2;
vector<vector<long long> > nums;
vector<long long> ans;
vector<long long> used;
vector<long long> a;
const long long MA = 1e18;
string s1, s2;

int main() {
    cin >> s1;
    cin >> s2;
    n = s1.size();
    m = s2.size();
    if (n == 0) {
        if (m == 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
        return 0;
    }
    if (m == 0) {
        for (int i = 0; i < n; i++) {
            if (s1[i] != '*') {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
        return 0;
    }
    dp1.resize(m + 1);
    dp2.resize(m + 1);
    dp1[0] = 1;
    int flag = 0;
    for (int i = 0; i <= m; i++) {
        if (s1[0] == '*') {
            dp1[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (s1[i - 1] == '*' && flag == 0) {
            dp2[0] = 1;
        } else {
            flag = 1;
        }
        for (int j = 1; j < m + 1; j++) {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?') {
                dp2[j] = dp1[j - 1];
            }
            if (s1[i - 1] == '*') {
                if (dp1[j - 1] == 1) {
                    dp2[j] = 1;
                } else {
                    dp2[j] = max(dp2[j - 1], dp1[j]);
                }
            }
        }
        swap(dp1, dp2);
        for (int j = 0; j <= m; j++) {
            dp2[j] = 0;
        }
    }
    if (dp1[m] == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}