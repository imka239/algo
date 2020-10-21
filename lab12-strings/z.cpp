#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int n, m;
vector<int> pref;
vector<int> answer;

int main() {
    string s1;
    cin >> s1;
    n = s1.size();
    pref.resize(n);
    int l = 0;
    int r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) {
            pref[i] = min(r - i + 1, pref[i - l]);
        }
        while (i + pref[i] < n && s1[pref[i]] == s1[i + pref[i]]) {
            ++pref[i];
        }
        if (i + pref[i] - 1 > r) {
            l = i;
            r = i + pref[i] - 1;
        }
        cout << pref[i] << " ";
    }
    return 0;
}