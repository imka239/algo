#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

long long unsigned int n;
int s, last;

int *resizing(int *St) {
    auto *new_st = (int*) malloc((size_t) s * sizeof(int));
    for (int i = 0; i < last; i++) {
        new_st[i] = St[i];
    }
    free(St);
    return new_st;
}

int main() {
    freopen("brackets.in", "r", stdin);
    freopen("brackets.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string strin;
    while (cin >> strin) {
        n = strin.size();
        s = 1;
        bool f = 0;
        last = 0;
        auto *St = (int*) malloc((size_t) s * sizeof(int));
        for (unsigned int i = 0; i < n; i++) {
            char c = strin[i];
            if (last == s) {
                s *= 2;
                St = resizing(St);
            }
            if (last * 4 <= s && s > 1) {
                s /= 2;
                St = resizing(St);
            }
            if (c == '(') {
                St[last] = 1;
                last++;
            }
            if (c == '[') {
                St[last] = 2;
                last++;
            }
            if (c == ')') {
                last--;
                //cout << St[last] << endl;
                if (last >= 0 && St[last] == 1) {
                    continue;
                } else {
                    cout << "NO" << endl;
                    free(St);
                    f = 1;
                    break;
                }
            }
            if (c == ']') {
                last--;
                //cout << St[last] << endl;
                if (last >= 0 && St[last] == 2) {
                    continue;
                } else {
                    cout << "NO" << endl;
                    free(St);
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0) {
            if (last == 0) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}