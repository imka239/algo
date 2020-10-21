#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <string>

using namespace std;

string s1, s2, ans;
int n, m;
vector<int> dp1;
vector<int> dp2;
vector<int> dp3;
vector<int> dp4;


void find_ans(int x1, int x2, int y1, int y2) {
    if (y2 == y1) {
        return;
    }
    if (y2 == y1 + 1) {
        for (int i = x1; i < x2; i++) {
            if (s1[i] == s2[y1]) {
                ans += s1[i];
                return;
            }
        }
        return;
    }
    for (int j = y1; j < (y1 + y2) / 2; j++) {
        for (int i = x1; i < x2; i++) {
            if (i == x1) {
                if (s1[i] == s2[j]) {
                    dp2[i] = 1;
                } else {
                    if (j == y1) {
                        dp2[i] = 0;
                    } else {
                        dp2[i] = dp1[i];
                    }
                }
            } else {
                if (j == y1) {
                    if (s1[i] == s2[j]) {
                        dp2[i] = 1;
                    } else {
                        dp2[i] = dp2[i - 1];
                    }
                } else {
                    if (s1[i] == s2[j]) {
                        dp2[i] = dp1[i - 1] + 1;
                    } else {
                        dp2[i] = max(dp2[i - 1], dp1[i]);
                    }
                }
            }
        }
        swap(dp1, dp2);
    }
    for (int j = y2 - 1; j >= (y1 + y2) / 2; j--) {
        for (int i = x2 - 1; i >= x1; i--) {
            if (i == x2 - 1) {
                if (s1[i] == s2[j]) {
                    dp4[i] = 1;
                } else {
                    if (j == y2 - 1) {
                        dp4[i] = 0;
                    } else {
                        dp4[i] = dp3[i];
                    }
                }
            } else {
                if (j == y2 - 1) {
                    if (s1[i] == s2[j]) {
                        dp4[i] = 1;
                    } else {
                        dp4[i] = dp4[i + 1];
                    }
                } else {
                    if (s1[i] == s2[j]) {
                        dp4[i] = dp3[i + 1] + 1;
                    } else {
                        dp4[i] = max(dp4[i + 1], dp3[i]);
                    }
                }
            }
        }
        swap(dp3, dp4);
    }
    int maxim = x1 - 1;
    int maxi = dp3[x1];
    if (dp1[x2 - 1] > dp3[x1]) {
        maxim = x2 - 1;
        maxi = dp1[x2 - 1];
    }
    for (int i = x1; i < x2 - 1; i++) {
        if (dp1[i] + dp3[i + 1] >= maxi) {
            maxi = dp1[i] + dp3[i + 1];
            maxim = i;
        }
    }
    if (maxim == x1 - 1) {
        find_ans(x1, x2, (y1 + y2) / 2, y2);
    } else {
        find_ans(x1, maxim + 1, y1, (y1 + y2) / 2);
        find_ans(maxim + 1, x2, (y1 + y2) / 2, y2);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    if (s1.size() < s2.size()) {
        swap(s1, s2);
    }
    n = (int) s1.size();
    dp1.resize(n);
    dp2.resize(n);
    dp3.resize(n);
    dp4.resize(n);
    m = (int) s2.size();
    find_ans(0, n, 0, m);
    cout << ans << endl;
    return 0;
}