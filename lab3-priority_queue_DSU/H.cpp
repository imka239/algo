#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<long long> mas;
vector<long long> colour;
vector<long long> bro;
long long a, b, x, shift, n, m;

long long get(long long now) {
    if (colour[now] != now) {
        colour[now] = get(colour[now]);
    }
    return colour[now];
}

int main() {
    cin >> n >> m;
    bro.resize(n);
    colour.resize(n);
    for (int i = 0; i < n; i++) {
        bro[i] = -1;
        colour[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> a >> b;
        a--; b--;
        a = (a + shift) % n;
        b = (b + shift) % n;
        a = get(a);
        b = get(b);
        if (x == 1) {
            if (a == b) {
                cout << "YES" << endl;
                shift = (shift + 1) % n;
            } else {
                cout << "NO" << endl;
            }
        } else {
            if (a != b) {
                if (bro[a] == -1) {
                    bro[a] = b;
                    if (bro[b] == -1) {
                        bro[b] = a;
                    } else {
                        colour[a] = bro[b];
                    }
                } else {
                    colour[b] = bro[a];
                    if (bro[b] != -1) {
                        colour[bro[b]] = a;
                    } else {
                        bro[b] = a;
                    }
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