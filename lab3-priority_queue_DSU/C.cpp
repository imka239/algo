#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<pair<long long, long long> > heapy;
vector<long long> pos;
vector<long long> elem;
string s;
int n, flag, bal;
int a, b;
long long k, m;

void pop_up(int now) {
    if (now == 0) {
        return;
    }
    if (heapy[(now - 1) / 2].first > heapy[now].first) {
        swap(pos[heapy[(now - 1) / 2].second], pos[heapy[now].second]);
        swap(heapy[(now - 1) / 2], heapy[now]);
        pop_up((now - 1) / 2);
    }
    return;
}

void pop_down(unsigned int now) {
    if (2 * now + 1 >= heapy.size()) {
        return;
    }
    if (2 * now + 2 < heapy.size()) {
        if (heapy[2 * now + 1].first < heapy[2 * now + 2].first) {
            if (heapy[now].first > heapy[2 * now + 1].first) {
                swap(pos[heapy[now].second], pos[heapy[2 * now + 1].second]);
                swap(heapy[now], heapy[2 * now + 1]);
                pop_down(2 * now + 1);
            }
        } else {
            if (heapy[now].first > heapy[2 * now + 2].first) {
                swap(pos[heapy[now].second], pos[heapy[2 * now + 2].second]);
                swap(heapy[now], heapy[2 * now + 2]);
                pop_down(2 * now + 2);
            }
        }
    } else {
        if (heapy[now].first > heapy[2 * now + 1].first) {
            swap(pos[heapy[now].second], pos[heapy[2 * now + 1].second]);
            swap(heapy[now], heapy[2 * now + 1]);
            pop_down(2 * now + 1);
        }
    }
    return;
}

int main() {
    freopen("priorityqueue2.in", "r", stdin);
    freopen("priorityqueue2.out", "w", stdout);
    int j = 0;
    while (cin >> s) {
        if (s[0] == 'p') {
            long long kek;
            cin >> kek;
            heapy.push_back(make_pair(kek, j));
            pos.push_back(heapy.size() - 1);
            pop_up((int) heapy.size() - 1);
        }
        if (s[0] == 'e') {
            pos.push_back(-1);
            if (heapy.size() == 0) {
                cout << "*" << endl;
                j++;
                continue;
            }
            cout << heapy[0].first << " " << heapy[0].second + 1 << endl;
            swap(pos[heapy[heapy.size() - 1].second], pos[heapy[0].second]);
            swap(heapy[heapy.size() - 1], heapy[0]);
            pos[heapy[heapy.size() - 1].second] = -1;
            heapy.pop_back();
            pop_down(0);
        }
        if (s[0] == 'd') {
            pos.push_back(-1);
            cin >> a >> b;
            int nw = (int) pos[(int) (a - 1)];
            if (nw == -1) {
                j++;
                continue;
            }
            heapy[nw].first = b;
            pop_up(nw);
            pop_down(nw);
        }
        j++;
    }
    return 0;
}