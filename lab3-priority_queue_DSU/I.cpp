#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <cstdio>

using namespace std;

queue<long long> colour;
queue<long long> ancolour;
long long n, m, batya, forik, lastec;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    batya = 1;
    forik = 1;
    lastec = 1;
    if (n == 1) {
        cout << "0 1 1";
        return 0;
    }
    while (m > 0) {
        cout << "1 " << batya + 1 << " " << batya << endl;
        batya++;
        m--;
        if (m > 0) {
            cout << "0 " << lastec << " " << lastec << endl;
            if (lastec == forik) {
                forik *= 2;
                lastec = 1;
            } else {
                lastec++;
            }
            m--;
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