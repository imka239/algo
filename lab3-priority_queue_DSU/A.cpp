#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> have;
int n;

int main() {
    freopen("isheap.in", "r", stdin);
    freopen("isheap.out", "w", stdout);
    cin >> n;
    have.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> have[i];
    }
    for (int i = 0; i < n; i++) {
        if (2 * i + 1 < n) {
            if (have[i] > have[2 * i + 1]) {
                cout << "NO" << endl;
                return 0;
            }
        }
        if (2 * i + 2 < n) {
            if (have[i] > have[2 * i + 2]) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}