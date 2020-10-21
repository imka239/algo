#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<vector<pair<int, int> > > ans;
vector<vector<pair<int, int> > > eas;
long long n;

int main() {
    cin >> n;
    long long answer = 0;
    vector<pair<int, int> > nex;
    for (int i = 2; i <= 16; i += 2) {
        nex.push_back(make_pair(i - 1, i));
    }
    ans.push_back(nex);
    nex.clear();
    for (int i = 4; i <= 16; i += 4) {
        nex.push_back(make_pair(i - 3, i));
    }
    for (int i = 3; i <= 16; i += 4) {
        nex.push_back(make_pair(i - 1, i));
    }
    ans.push_back(nex);
    nex.clear();
    for (int i = 2; i <= 16; i += 2) {
        nex.push_back(make_pair(i - 1, i));
    }
    ans.push_back(nex);
    nex.clear();
    for (int i = 1; i <= 4; i += 1) {
        nex.push_back(make_pair(i, 9 - i));
        nex.push_back(make_pair(i + 8, 17 - i));
    }
    ans.push_back(nex);
    nex.clear();
    for (int i = 4; i <= 16; i += 4) {
        nex.push_back(make_pair(i - 2, i));
        nex.push_back(make_pair(i - 3, i - 1));
    }
    ans.push_back(nex);
    nex.clear();
    for (int i = 2; i <= 16; i += 2) {
        nex.push_back(make_pair(i - 1, i));
    }
    ans.push_back(nex);
    nex.clear();
    for (int i = 1; i <= 8; i += 1) {
        nex.push_back(make_pair(i, 17 - i));
    }
    ans.push_back(nex);
    nex.clear();
    for (int i = 1; i <= 4; i += 1) {
        nex.push_back(make_pair(i, 4 + i));
        nex.push_back(make_pair(i + 8, 12 + i));
    }
    ans.push_back(nex);
    nex.clear();
    for (int i = 1; i <= 13; i += 4) {
        nex.push_back(make_pair(i, 2 + i));
        nex.push_back(make_pair(i + 1, 3 + i));
    }
    ans.push_back(nex);
    nex.clear();
    for (int i = 2; i <= 16; i += 2) {
        nex.push_back(make_pair(i - 1, i));
    }
    ans.push_back(nex);
    nex.clear();
    for (unsigned int i = 0; i < ans.size(); i++) {
        nex.clear();
        for (unsigned int j = 0; j < ans[i].size(); j++) {
            if (ans[i][j].first <= n && ans[i][j].second <= n) {
                nex.push_back(ans[i][j]);
                answer++;
            }
        }
        if (nex.size() != 0) {
            eas.push_back(nex);
        }
    }
    cout << n << " " << answer << " " << eas.size() << endl;
    for (unsigned int i = 0; i < eas.size(); i++) {
        cout << eas[i].size() << " ";
        for (unsigned int j = 0; j < eas[i].size(); j++) {
            cout << eas[i][j].first << " " << eas[i][j].second << " ";
        }
        cout << endl;
    }
    return 0;
}