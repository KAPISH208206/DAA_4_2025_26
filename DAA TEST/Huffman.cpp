#include <bits/stdc++.h>
using namespace std;
struct Node {
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct cmp {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

int main() {
    string s;
    cin >> s;

    vector<int> f(26, 0);
    for (char c : s) {
        f[c-'a']++;
    }

    priority_queue<Node*, vector<Node*>, cmp> pq;
    for (int i =0; i<26; i++) {
        if (f[i] > 0) {
            pq.push(new Node(char('a'+i),f[i]));
        }
    }

    return 0;
}
