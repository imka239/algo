#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> pref;
vector<int> diff;
vector<pair<int, int> > zapr;
string s;

void pref_func(int from) {
    pref[from] = 0;
    diff[from] = 1;
    cout << 0 << " ";
    for (int i = from - 1; i >= 0; --i) {
        int j = pref[i + 1];
        while (j != 0 && s[from - j] != s[i]) {
            j = pref[from - j + 1];
        }
        if (s[i] == s[from - j]) {
            j++;
        }
        pref[i] = j;
        cout << j << " ";
    }
}

int main() {
    cin >> s;
    n = s.size();
    zapr.resize(m);
    diff.resize(n);
    pref.resize(n);
    reverse(s.begin(), s.end());
    pref_func(n - 1);
    return 0;
}