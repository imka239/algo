include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<long long> colour;
vector<long long> value;
long long a, b, x, shift, n, m, val;
long long p = 1000003;

long long get(long long now) {
    if (colour[now] != now) {
        x = get(colour[now]);
        if (colour[colour[now]] != colour[now]) {
            value[now] += value[colour[now]];
        }
        colour[now] = x;
    }
    return colour[now];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    colour.resize(n);
    value.resize(n);
    for (int i = 0; i < n; i++) {
        colour[i] = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> x >> a;
        a = (a + shift) % n;
        if (x == 1) {
            val = 0;
            a = get(a);
            value[a] += 1;
            shift = (shift * 30 + 239) % p;
        } else {
            if (x == 2) {
                val = 0;
                a = get(a);
                cin >> b;
                b = (b + shift) % n;
                val = 0;
                b = get(b);
                if (a != b) {
                    colour.push_back(colour.size());
                    value.push_back(0);
                    colour[a] = colour.size() - 1;
                    colour[b] = colour.size() - 1;
                    shift = (shift * 13 + 11) % p;
                }
            } else {
                val = 0;
                long long c = get(a);
                long long d = 0;
                if (a != c) {
                    d = value[a] + value[c];
                    value[a] = -value[c];
                } else {
                    d = value[a];
                    value[a] = 0;
                }
                cout << d << endl;
                shift = (shift * 100500 + d) % p;
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