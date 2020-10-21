#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>

#define ull unsigned long long
using namespace std;

unsigned long long answer;
unsigned int a, b;
const int BIG = 1 << 16;
int t, n;

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
    freopen("buckets.in", "r", stdin);
    freopen("buckets.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> n;
    cin >> a >> b;
    int have[100001][2];
    int have1[100001][2];
    int let[BIG];
    for (int h = 0; h < t; h++) {
        for (int i = 0; i < n; i++) {
            ull nex = nextRand32();
            have[i][1] = (nex & 0xffff0000) >> 16;
            have[i][0] = (nex & 0x0000ffff);
        }
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < BIG; j++) {
                let[j] = 0;
            }
            for (int j = 0; j < n; j++) {
                let[have[j][i]]++;
            }
            int su = 0;
            for (int j = 0; j < BIG; j++) {
                su += let[j];
                let[j] = su - let[j];
            }
            for (int j = 0; j < n; j++) {
                have1[let[have[j][i]]][0] = have[j][0];
                have1[let[have[j][i]]][1] = have[j][1];
                let[have[j][i]]++;
            }
            for (int j = 0; j < n; j++) {
                have[j][0] = have1[j][0];
                have[j][1] = have1[j][1];
            }
        }
        answer = 0;
        for (int i = 0; i < n; i++) {
            answer += (ull)(have[i][0] + ((ull) have[i][1] << 16)) * (i + 1);
        }

        cout << answer << endl;
    }
    return 0;
}