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
    freopen("queue2.in", "r", stdin);
    freopen("queue2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    st *head = nullptr;
    st *tail = nullptr;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            cin >> s;
            st *new_head = new st(nullptr, s);
            if (head != nullptr) {
                head->next = new_head;
            }
            if (tail == nullptr) {
                tail = new_head;
            }
            head = new_head;
        } else {
            cout << tail->x << endl;
            st *new_tail = tail->next;
            if (head == tail) {
                head = nullptr;
            }
            free(tail);
            tail = new_tail;
        }
    }
}