#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

long long n, m, k;
string s;
vector<vector<long long> > matrix;
vector<vector<long long> > matr;
vector<vector<long long> > st;
vector<vector<long long> > nex;
long long ans;
vector<int> start;
long long MA;

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

void half() {
    for (int i = (int) start.size() - 1; i >= 0; i--) {
        if (start[i] % 2 == 1) {
            start[i - 1] += 10;
        }
        start[i] /= 2;
    }
    if (start[start.size() - 1] == 0) {
        start.pop_back();
    }
}

void minusOne() {
    for (int i = 0; i < (int) start.size(); i++) {
        if (start[i] > 0) {
            start[i]--;
            break;
        } else {
            start[i] = 9;
        }
    }
    if (start[start.size() - 1] == 0) {
        start.pop_back();
    }
}

vector<vector<long long> > lets_go() {
    if (start.size() == 1 && start[0] == 1) {
        return matrix;
    }
    if (start[0] % 2 == 1) {
        minusOne();
        return mult(matrix, lets_go());
    } else {
        half();
        nex = lets_go();
        return mult(nex, nex);
    }
}

void parse() {
    for (int i = (int) s.size() - 1; i >= 0; i--) {
        start.push_back(s[i] - '0');
    }
}

int main() {
    freopen("nice3.in", "r", stdin);
    freopen("nice3.out", "w", stdout);
    cin >> s >> m >> MA;
    matrix.resize((1 << m));
    st.resize((1 << m));
    parse();
    for (int i = 0; i < (1 << m); i++) {
        st[i].push_back(1);
    }
    if (s.size() == 1 && s[0] == '1') {
        cout << (1 << m) % MA << endl;
        return 0;
    }
    matr.resize((1 << m));
    for (int i = 0; i < (1 << m); i++) {
        matr[i].resize((1 << m));
        matrix[i].resize((1 << m));
        for (int j = 0; j < (1 << m); j++) {
            int flag = 0;
            for (int h = 1; h < m; h++) {
                if (((i & (1 << h)) && (i & (1 << (h - 1)))
                     && (j & (1 << h)) && (j & (1 << (h - 1)))) ||
                    (!(i & (1 << h)) && !(i & (1 << (h - 1)))
                     && !(j & (1 << h)) && !(j & (1 << (h - 1))))) {
                    flag = 1;
                }
            }
            if (flag == 0) {
                matrix[i][j] = 1;
            }
            matr[i][j] = matrix[i][j];
        }
    }
    minusOne();
    matr = lets_go();
    nex = mult(matr, st);
    ans = 0;
    for (int i = 0; i < (1 << m); i++) {
        ans = (ans + nex[i][0]) % MA;
    }
    cout << ans % MA << endl;
    return 0;
}