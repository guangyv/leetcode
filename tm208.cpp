//
// Created by dgy on 2024/4/20.
//
#include <bits/stdc++.h>
using namespace std;

class Trie {
private:
    vector<Trie*> child;
    bool isEnd;

    Trie* searchPrefix(string prefix) {
        Trie* node = this;
        for (char ch : prefix) {
            ch -= 'a';
            if (node->child[ch] == nullptr) {
                return nullptr;
            }
            node = node->child[ch];
        }
        return node;
    }
public:
    Trie() {
        child.resize(26);
        isEnd = false;
    }

    void insert(string word) {
        Trie* node = this;
        for (char ch : word) {
            ch -= 'a';
            if (node->child[ch] == nullptr) {
                node->child[ch] = new Trie();
            }
            node = node->child[ch];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = this->searchPrefix(word);
        return node != nullptr && node->isEnd;
    }

    bool startsWith(string prefix) {
        Trie* node = this->searchPrefix(prefix);
        return node != nullptr;
    }
};

int main() {
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple");   // 返回 True
    cout << trie.search("app");     // 返回 False
    cout << trie.startsWith("app"); // 返回 True
    trie.insert("app");
    cout << trie.search("app");     // 返回 True
}