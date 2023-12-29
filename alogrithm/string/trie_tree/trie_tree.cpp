#include <unordered_map>
#include <algorithm>
#include <string>
#include <cassert>
using namespace std;
struct TrieTreeNode {
    unordered_map<char , TrieTreeNode*> m_children;
    bool flag = false;
};
class Trie {
public:
    Trie() {
        m_root = new TrieTreeNode();
    }
    ~Trie() {
        deleteNodes(m_root);
    }
    
    void insert(string  word) {
        TrieTreeNode* cur = m_root;
        for(char elem: word) {
            auto pair = cur->m_children.find(elem);
            if(cur->m_children.end() == pair) { //
                auto it = cur->m_children.emplace_hint(pair, elem,  new TrieTreeNode());
                cur= it->second;
            } else {
                cur = pair->second;
            }
        }
        cur->flag = true;
    }
    
    bool search(string word) {
        TrieTreeNode* cur = m_root;
        for(char elem: word) {
            auto pair = cur->m_children.find(elem);
            if(cur->m_children.end() == pair) return false;
            cur = pair->second;

        }
        return cur->flag;
    }
    
    bool startsWith(string prefix) {
        TrieTreeNode* cur = m_root;
        for(char elem: prefix) {
            auto pair = cur->m_children.find(elem);
            if(cur->m_children.end() == pair) return false;
            else {
                cur = pair->second;
            }
        }
        return true;
    }
private:
    TrieTreeNode* m_root;

    void deleteNodes(TrieTreeNode* node) {
        for (auto& kv : node->m_children) {
            deleteNodes(kv.second);
        }
        delete node;
    }
};


int main () {
    Trie trie;
    trie.insert("apple");
    assert(true == trie.search("apple"));
}
