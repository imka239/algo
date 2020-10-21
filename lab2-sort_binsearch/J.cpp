#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> kek;
vector<long long> ror;
vector<long long> lol;
unsigned int a, b, n;
long long answer, k;

void sorting(int lef, int rig) {
    if (rig == lef + 1) {
        return;
    }
    sorting(lef, (rig + lef) / 2);
    sorting((rig + lef) / 2, rig);
    int le2 = lef;
    lol.resize(rig - lef);
    int le3 = (rig + lef) / 2;
    while (le2 < (rig + lef) / 2) {
        while (le3 < rig && kek[le3] - kek[le2] < k) {
            le3++;
        }
        answer += (rig - le3);
        le2++;
    }
    int m = 0;
    le2 = lef;
    le3 = (rig + lef) / 2;
    while (le2 < (rig + lef) / 2 || le3 < rig) {
        if (le2 == (rig + lef) / 2) {
            lol[m] = kek[le3];
            le3++;
            m++;
            continue;
        }
        if (le3 == rig) {
            lol[m] = kek[le2];
            le2++;
            m++;
            continue;
        }
        if (kek[le2] < kek[le3]) {
            lol[m] = kek[le2];
            le2++;
            m++;
        } else {
            lol[m] = kek[le3];
            le3++;
            m++;
        }
    }
    for (int i = 0; i < rig - lef; i++) {
        kek[lef + i] = lol[i];
    }
}

unsigned int cur = 0;
unsigned int nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}
unsigned int nextRand32() {
    unsigned int c = nextRand24(), d = nextRand24();
    return (c << 8) ^ d;
}

int main() {
    freopen("bigseg.in", "r", stdin);
    freopen("bigseg.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cin >> a >> b;
    ror.resize(n);
    kek.resize(n);
    for (unsigned int i = 0; i < n; i++) {
        ror[i] = (int) nextRand32();
    }
    kek[0] = ror[0];
    if (kek[0] >= k) {
        answer++;
    }
    for (unsigned int i = 1; i < n; i++) {
        kek[i] = ror[i] + kek[i - 1];
        if (kek[i] >= k) {
            answer++;
        }
    }
    sorting(0, n);
    cout << answer << endl;
    return 0;
}