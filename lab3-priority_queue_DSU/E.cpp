#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> colour;
vector<int> otr;
int a, b, x, shift, n, m;

int get1(int now) {
    if (colour[now] != now) {
        colour[now] = get1(colour[now]);
    }
    return colour[now];
}

int get2(int now) {
    if (otr[now] != now) {
        otr[now] = get2(otr[now]);
    }
    return otr[now];
}

int main() {
    freopen("restructure.in", "r", stdin);
    freopen("restructure.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    colour.resize(n);
    otr.resize(n);
    for (int i = 0; i < n; i++) {
        colour[i] = i;
        otr[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> a >> b;
        a--; b--;
        if (x == 1) {
            a = get1(a);
            b = get1(b);
            colour[a] = b;
        } else {
            if (x == 2) {
                while (true) {
                    a = get2(a);
                    if (a >= b) {
                        break;
                    }
                    int c = get1(a + 1);
                    int d = get1(a);
                    colour[d] = c;
                    otr[a] = a + 1;
                }
            } else {
                a = get1(a);
                b = get1(b);
                if (a == b) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}
/*
3 3
2 2 -500
1 2 -760
1 3 -1000
*/