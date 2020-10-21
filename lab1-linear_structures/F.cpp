#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>

using namespace std;

int n, s, last;

struct st {
    st *next;
    int x;

    st(st *next, int x) : next(next), x(x) {}

    explicit st(int x) : next(nullptr), x(x) {}
};

int main() {
    freopen("postfix.in", "r", stdin);
    freopen("postfix.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str;
    st *head = nullptr;
    while (cin >> str) {
        char c;
        c = str[0];
        if (c == ' ') {
            continue;
        }
        if (c == '+' || c == '*' || c == '-') {
            int a = head->x;
            int b = head->next->x;
            int res = 0;
            if (c == '+') {
                res = a + b;
            }
            if (c == '-') {
                res = b - a;
            }
            if (c == '*') {
                res = a * b;
            }
            head = head->next;
            head->x = res;
            //cout << res << endl;
        } else {
            int next_s = c - '0';
            //cout << next_s << endl;
            st *new_head = new st(head, next_s);
            head = new_head;
        }
    }
    cout << head->x << endl;
    return 0;
}