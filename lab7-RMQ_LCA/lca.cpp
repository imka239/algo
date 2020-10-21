#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

long long n;
vector<vector<int> > pred;
vector<int> two;
vector<int> heigh;

void lca(int a, int b) {
    if (heigh[a] < heigh[b]) {
        swap(a, b);
    }
    int now = 19;
    while (heigh[a] > heigh[b]) {
        if (heigh[pred[a][now]] >= heigh[b]) {
            a = pred[a][now];
        }
        now--;
    }
    now = 19;
    while (a != b && now >= 0) {
        if (pred[a][now] != pred[b][now]) {
            a = pred[a][now];
            b = pred[b][now];
        }
        now--;
    }
    if (a != b) {
        cout << pred[a][0] + 1 << "\n";
    } else {
        cout << b + 1 << "\n";
    }
}

int main() {
    /*two.resize(20);
    two[0] = 1;
    for (int i = 1; i < 20; i++) {
        two[i] = two[i - 1] * 2;
    }*/
    ios_base::sync_with_stdio(0);
    cin >> n;
    pred.resize(500000);
    heigh.resize(500000);
    pred[0].resize(20);
    for (int i = 0; i < n; i++) {
        string s; int a, b;
        cin >> s >> a >> b;
        if (s[0] == 'A') {
            pred[b - 1].resize(20);
            pred[b - 1][0] = a - 1;
            heigh[b - 1] = heigh[a - 1] + 1;
            for (int j = 1; j < 20; j++) {
                pred[b - 1][j] = pred[pred[b - 1][j - 1]][j - 1];
            }
        } else {
            lca(a - 1, b - 1);
        }
    }
    return 0;
}