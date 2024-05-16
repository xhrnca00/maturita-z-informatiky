#include <fstream>
#include <iostream>
#include <map>

struct Node {
    Node *next = nullptr;
    std::string k;
    int v = 1;
    explicit Node(const std::string &k, Node *next) : next(next), k(k) {
    }
};

struct Trie {
    int v = 0;
    std::map<char, Trie> next;
};

Node *freqs(const char filename[]);
Trie fqs(const char filename[]);
void print_trie(const Trie &trie);

constexpr char FNAME[] = "ZPRAVA.TXT";

int main() {
    // O(n^2)
    auto l = freqs(FNAME);
    while (l != nullptr) {
        std::cout << l->k << ": " << l->v << '\n';
        auto old = l;
        l = l->next;
        delete old;
    }
    std::cout << "-------------------\n";
    // O(n)
    auto f = fqs(FNAME);
    print_trie(f);
    return 0;
}

Node *freqs(const char filename[]) {
    std::ifstream f(filename);
    if (!f.is_open())
        abort();
    std::string w;
    Node *list = nullptr;
    while (f >> w) {
        Node *curr = list;
        while (curr != nullptr) {
            if (curr->k == w) {
                curr->v += 1;
                goto CONTINUE;
            }
            curr = curr->next;
        }
        list = new Node(w, list);
    CONTINUE:;
    }
    f.close();
    return list;
}

Trie fqs(const char filename[]) {
    std::ifstream f(filename);
    if (!f.is_open())
        abort();
    std::string w;
    Trie trie;
    while (f >> w) {
        Trie *curr = &trie;
        auto c = w.begin();
        while (c != w.end()) {
            if (!curr->next.count(*c))
                curr->next[*c] = Trie();
            curr = &curr->next[*c];
            ++c;
        }
        curr->v += 1;
    }
    f.close();
    return trie;
}

void print_trie_r(const Trie &trie, std::string &pref) {
    if (trie.v)
        std::cout << pref << ": " << trie.v << '\n';
    for (const auto &[l, n] : trie.next) {
        pref.push_back(l);
        print_trie_r(n, pref);
        pref.pop_back();
    }
}
void print_trie(const Trie &trie) {
    std::string s;
    print_trie_r(trie, s);
}
