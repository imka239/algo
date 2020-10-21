#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> have;
vector<pair<int, int> > ans;
int n, can;

void go(int l, int r) {
    if (r - l <= 2) {
        if (have[l] <= have[l + 1]) {
            can = 1;
        }
        return;
    }
    int flag = 0;
    int answer = 0;
    for (int i = l + 1; i < r; i++) {
        if (have[i] == 1) {
            flag = 1;
        } else {
            if (flag == 1) {
                answer = 1;
            }
        }
    }
    if (answer == 1) {
        go(l + 1, r);
        if (have[l] == 0) {
            for (int i = r - 1; i >= l + 1; i--) {
                ans.push_back(make_pair(l, i));
            }
        } else {
            for (int i = l + 1; i < r; i++) {
                ans.push_back(make_pair(i - 1, i));
            }
        }
    } else {
        flag = 0;
        answer = 0;
        for (int i = l; i < r - 1; i++) {
            if (have[i] == 1) {
                flag = 1;
            } else {
                if (flag == 1) {
                    answer = 1;
                }
            }
        }
        if (answer == 1) {
            go(l, r - 1);
            if (have[r - 1] == 1) {
                for (int i = l; i < r - 1; i++) {
                    ans.push_back(make_pair(i, r - 1));
                }
            } else {
                for (int i = r - 2; i >= l; i--) {
                    ans.push_back(make_pair(i, i + 1));
                }
            }
        } else {
            can = 1;
            return;
        }
    }
}

int main() {
    cin >> n;
    while (n != 0) {
        have.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> have[i];
        }
        can = 0;
        go(0, n);
        if (can == 1) {
            cout << -1 << endl;
        } else {
            cout << ans.size() << endl;
            for (unsigned int i = 0; i < ans.size(); i++) {
                cout << ans[i].first + 1 << " " << ans[i].second + 1 << endl;
            }
        }
        cin >> n;
        ans.clear();
    }
    return 0;
}