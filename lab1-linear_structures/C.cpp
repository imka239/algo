#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int n, s, last, pre;

int *change(int *St) {
    auto *new_st = (int*) malloc((size_t) s * sizeof(int));
    for (int i = last - 1; i >= 0; i--) {
        new_st[last - i - 1] = St[i];
    }
    free(St);
    return new_st;
}

int *resizing(int *St) {
    auto *new_st = (int*) malloc((size_t) s * sizeof(int));
    for (int i = 0; i < last; i++) {
        new_st[i] = St[i];
    }
    free(St);
    return new_st;
}

int main() {
    freopen("queue1.in", "r", stdin);
    freopen("queue1.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    s = 1;
    last = 0;
    pre = 0;
    auto *St = (int*) malloc((size_t) s * sizeof(int));
    auto *Pr = (int*) malloc((size_t) s * sizeof(int));
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (last == s) {
            s *= 2;
            St = resizing(St);
        }
        if (last * 4 <= s && s > 1) {
            s /= 2;
            St = resizing(St);
        }
        if (c == '+') {
            cin >> St[last];
            last++;
        } else {
            if (pre > 0) {
                pre--;
                cout << Pr[pre] << endl;
            } else {
                Pr = change(St);
                pre = last;
                last = 0;
                s = 1;
                St = (int*) malloc((size_t) s * sizeof(int));
                pre--;
                cout << Pr[pre] << endl;
            }
        }
    }
}