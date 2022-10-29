#include <bits/stdc++.h>

using namespace std;

struct TrieNode {
    TrieNode* child[26];
    int cnt;
    TrieNode() {
        for (int i = 0; i < 26; ++i) child[i] = NULL;
        cnt = 0;
    }
};

class Trie{
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete_(root);        
        delete root;
    }   
    
    void delete_(TrieNode* root) {
        if (root == NULL) return;        
        for (int i = 0; i < 26; ++i) {
            if (root->child[i] != NULL) delete_(root->child[i]); 
        }
        delete root;
        root = NULL;
    }
    void TrieInsert(const string& s) {
        if (root == NULL) {
            root = new TrieNode();
        }
        int n = s.length();
        TrieNode* p = root;
        for (int i = 0; i < n; ++i) {
            int nxt = s[i] - 'a';
            if (p->child[nxt]==NULL) 
                p->child[nxt] = new TrieNode();
            p = p->child[nxt];
        }
        ++p->cnt;
    }
    
    bool TrieFind(const string& s) {
        if (root == NULL) return false;
        int n = s.length();
        TrieNode* p = root;
        for (int i = 0; i < s.length(); ++i) {
            int nxt = s[i] - 'a';
            if (p->child[nxt]==NULL)
                return false;
            p = p->child[nxt];
        }
        cout << "s: " << p->cnt << endl; 
        return p->cnt > 0;
    }
    
    void TrieDelete(const string& s) {
        if (root == NULL) return;
        int n = s.length();
        TrieNode* p = root;
        for (int i = 0; i < s.length(); ++i) {
            int nxt = s[i] - 'a';
            if (p->child[nxt]==NULL) {
                if (p->cnt != 0) p->cnt--;
                return;
            }
            p = p->child[nxt];
        }
        if (p->cnt != 0) p->cnt--;
        return;
    }
    
};


int main() {
    string keys[] = { "the", "a", "there",
                      "answer", "any", "by",
                      "bye", "their", "hero", "heroplane" ,"bye","bye"};
    int n = sizeof(keys)/sizeof(keys[0]);
    Trie trie;
    for (int i = 0; i < n; ++i) trie.TrieInsert(keys[i]);
    
    
    return 0;
}