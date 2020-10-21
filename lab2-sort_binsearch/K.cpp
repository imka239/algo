#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> ans;
vector<vector<long long> > cash;
long long n, x, st, m, fir;
const long long BIG = 1000000000000000000;

int main() {
    cin >> x >> m;
    cout << "? " << 1 << endl;
    cin >> st;
    if (st == x) {
        cout << "! " << 1 << endl;
        return 0;
    }
    fir = (x - st + BIG) % BIG;
    long long l = fir - m;
    long long r = fir + 2;
    long long ne;
    long long have = 1;
    while (l < r - 1) {
        long long mid = (l + r) / 2;
        cout << "? " << (mid - 1 + BIG - m) % (BIG - m) + 1 << endl;
        have++;
        cin >> ne;
        if (ne == x) {
            cout << "! " << (mid - 1 + BIG - m) % (BIG - m) + 1 << endl;
            return 0;
        }
        if (ne > x + 501) {
            ne -= BIG;
        }
        if (ne < x - 501) {
            ne += BIG;
        }
        if (ne < x) {
            l = mid;
        } else {
            r = mid;
        }
    }
    if (have < 10) {
        cout << "? " << l + 1 << endl;
        have++;
        cin >> ne;
    }
    if (ne == x) {
        cout << "! " << l + 1 << endl;
    } else {
        cout << "! -1" << endl;
    }
    return 0;
}