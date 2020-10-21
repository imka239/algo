#include <bits/stdc++.h>

using namespace std;

struct node {
    node* letters[26];
    vector<int> gabella;
    node* suf_mail, *pred;
    int last_symb;
    node() {
        fill(letters, letters + 26, nullptr);
        suf_mail = nullptr;
        pred = nullptr;
        gabella.clear();
        last_symb = 1;
    }
};

void make_bor(node * now, string& s, int ind, int j) {
    if (ind == (int) s.size()) {
        now->gabella.push_back(j);
        return;;
    }
    if (now->letters[s[ind] - 'a'] == nullptr) {
        node* new_node = new node();
        new_node->last_symb = s[ind] - 'a';
        new_node->pred = now;
        now->letters[s[ind] - 'a'] = new_node;
    }
    make_bor(now->letters[s[ind] - 'a'], s, ind + 1, j);
}

set<node*> used;
queue<node*> que;
vector<int> ans;

void go(node * now, string& s, int ind) {
    used.insert(now);
    if (ind == (int) s.size()) {
        return;
    }
    go(now->letters[s[ind] - 'a'], s, ind + 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    node * root = new node();
    root->pred = root;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s1;
        cin >> s1;
        make_bor(root, s1, 0, i + 1);
    }
    root->suf_mail = root;
    queue<node*> bfs;
    bfs.push(root);
    while (!bfs.empty()) {
        node * next = bfs.front();
        bfs.pop();
        int next_char = next->last_symb;
        if (next == root) {
            for (int i = 0; i < 26; i++) {
                if (next->letters[i] != nullptr) {
                    bfs.push(next->letters[i]);
                } else {
                    next->letters[i] = next;
                }
            }
            continue;
        }
        node * now = next->pred;
        if (now == root) {
            next->suf_mail = now;
            for (int i = 0; i < 26; i++) {
                if (next->letters[i] != nullptr) {
                    bfs.push(next->letters[i]);
                } else {
                    next->letters[i] = next->suf_mail->letters[i];
                }
            }
            continue;
        }
        next->suf_mail = next->pred->suf_mail->letters[next_char];
        for (int i = 0; i < 26; i++) {
            if (next->letters[i] != nullptr) {
                bfs.push(next->letters[i]);
            } else {
                next->letters[i] = next->suf_mail->letters[i];
            }
        }
    }
    ans.resize(n);
    string s;
    cin >> s;
    go(root, s, 0);
    for (auto& i : used) {
        que.push(i);
    }
    while (!que.empty()) {
        node * now = que.front();
        que.pop();
        if (now->gabella.size() != 0) {
            for (unsigned int i = 0; i < now->gabella.size(); i++) {
                ans[now->gabella[i] - 1] = 1;
            }
        }
        if (used.count(now->suf_mail) == 0) {
            used.insert(now->suf_mail);
            que.push(now->suf_mail);
        }
    }
    for (int j = 0; j < n; ++j) {
        if (ans[j] == 1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}