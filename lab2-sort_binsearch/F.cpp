#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int n, k, b, c, fi, se;
vector<int> a;
vector<int> ans;

int main() {
    freopen("antiqs.in", "r", stdin);
    freopen("antiqs.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    a.resize(n + 1);
    ans.resize(n + 1);
    for (int i = 1; i < n + 1; i++) {
        a[i] = i;
    }
    for (int i = 1; i < n + 1; i++) {
        ans[a[(n - i + 2) / 2]] = n - i + 1;
        swap(a[n - i + 1], a[(n - i + 2) / 2]);
    }
    for (int i = 1; i < n + 1; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}