#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int n, s, last;

struct st {
    st *next;
    int x;

    st(st *next, int x) : next(next), x(x) {}

    explicit st(int x) : next(nullptr), x(x) {}
};

int main() {
    //freopen("stack2.in", "r", stdin);
    //freopen("stack2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    st *head = nullptr;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            cin >> s;
            st *new_head = new st(head, s);
            head = new_head;
        } else {
            cout << head->x << endl;
            st *new_head = head->next;
            free(head);
            head = new_head;
        }
    }
}