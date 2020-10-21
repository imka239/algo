#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int n, k, b, c, fi, se, m;
vector<string> a;
vector<int> let;
vector<int> ans;
vector<int> ans1;

int main() {
    freopen("radixsort.in", "r", stdin);
    freopen("radixsort.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    a.resize(n);
    ans.resize(n);
    ans1.resize(n);
    let.resize(26);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ans[i] = i;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 26; j++) {
            let[j] = 0;
        }
        for (int j = 0; j < n; j++) {
            let[a[ans[j]][m - i - 1] - 'a']++;
        }
        int su = 0;
        for (int j = 0; j < 26; j++) {
            su += let[j];
            let[j] = su - let[j];
        }
        for (int j = 0; j < n; j++) {
            ans1[let[a[ans[j]][m - i - 1] - 'a']] = ans[j];
            let[a[ans[j]][m - i - 1] - 'a']++;
        }
        swap(ans1, ans);
    }
    for (int i = 0; i < n; i++) {
        cout << a[ans[i]] << endl;
    }
    return 0;
}