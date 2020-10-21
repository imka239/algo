#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>

using namespace std;

long long n, m, k;
vector<vector<long long> > matrix;
vector<vector<long long> > matr;
vector<vector<long long> > st;
vector<vector<long long> > nex;
long long ans;
const int MA = 999999937;

vector<vector<long long> > mult(vector<vector<long long> > a1, vector<vector<long long> > a2) {
    vector<vector<long long> > a3;
    a3.resize(a1.size());
    for (unsigned int i = 0; i < a1.size(); i++) {
        a3[i].resize(a2[0].size());
        for (unsigned int j = 0; j < a2[0].size(); j++) {
            a3[i][j] = 0;
            for (unsigned int h = 0; h < a2.size(); h++) {
                a3[i][j] = (a3[i][j] + a1[i][h] * a2[h][j]) % MA;
            }
        }
    }
    return a3;
}

vector<vector<long long> > lets_go(long long now) {
    if (now == 1) {
        return matrix;
    }
    if (now % 2 == 1) {
        return mult(matrix, lets_go(now - 1));
    } else {
        nex = lets_go(now / 2);
        return mult(nex, nex);
    }
}

int main() {
    freopen("sequences.in", "r", stdin);
    freopen("sequences.out", "w", stdout);
    matrix.resize(5);
    st.resize(5);
    matrix[0] = {1, 1, 1, 1, 1};
    matrix[1] = {1, 1, 1, 1, 1};
    matrix[2] = {1, 1, 1, 1, 1};
    matrix[3] = {1, 1, 0, 1, 0};
    matrix[4] = {1, 1, 0, 1, 0};
    st = {{1},
          {1},
          {1},
          {1},
          {1}};
    cin >> n;
    while (n != 0) {
        if (n == 1) {
            cout << 5 << endl;
            cin >> n;
            continue;
        }
        matr.resize(5);
        for (int i = 0; i < 5; i++) {
            matr[i].resize(5);
            for (int j = 0; j < 5; j++) {
                matr[i][j] = matrix[i][j];
            }
        }
        matr = lets_go(n - 1);
        nex = mult(matr, st);
        ans = 0;
        for (int i = 0; i < 5; i++) {
            ans = (ans + nex[i][0]) % MA;
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}