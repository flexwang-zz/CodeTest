#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct TrieNode
{
    TrieNode():cnt(0){}
    unordered_map<char, TrieNode*> um;
    int cnt;
};

class Trie{
public:
    Trie():root(new TrieNode()){}
    void insert(const string& str) {
        TrieNode *node = root;
        for (int i=0; i<str.length(); i++) {
            if (node->um.find(str[i]) == node->um.end())
                node->um[str[i]] = new TrieNode();
            node = node->um[str[i]];
            node->cnt++;
        }
    }
    int search(const string& str) {
        TrieNode *node = root;
        for (int i=0; i<str.length(); i++) {
            if (node->um.find(str[i]) == node->um.end()) return 0;
            node = node->um[str[i]];
        }
        return node->cnt;
    }
private:
    TrieNode *root;
};

int main()
{
    Trie trie;
    int n, m;
    cin >> n;
    for (int i=0; i<n; i++) {
        string str;
        cin >> str;
        trie.insert(str);
    }
    cin >> m;
    for (int i=0; i<m; i++) {
        string str;
        cin >> str;
        cout << trie.search(str) << endl;
    }
    return 0;
}