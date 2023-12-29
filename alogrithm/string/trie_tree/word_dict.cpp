#include <string>
using namespace std;
class WordDictionary {
public:
    WordDictionary() {

    }
    
    void addWord(string word) {
        WordDictionary* cur = this;
        for(char elem: word) {
            int index = elem - 'a';
            if(nullptr ==  cur->m_children[index]) {
                cur->m_children[index] = new WordDictionary();
            }
            cur = cur->m_children[index];
        }
        cur->isEnd = true;
    }
    
    bool search(string word) {
        WordDictionary* cur = this;
        return search_recursive(cur,word,0);
    }

    bool search_recursive(WordDictionary* cur,string val, int start) {
        if(start == val.size()) return cur->isEnd;
        for(int i = start; i< val.size(); i++) {
            char elem = val[i];
            if(elem == '.') {
                for(int j = 0; j < 26; j++) {
                    if(nullptr != cur->m_children[j] 
                    && search_recursive(cur->m_children[j],val, i + 1)) return true;
                }
                return false;
            } else {
                int index = elem - 'a';
                if(nullptr ==  cur->m_children[index]) return false;
                cur = cur->m_children[index];
            }
        }
        return cur->isEnd;
    }
    private:
        WordDictionary*  m_children[26] = {nullptr};
        bool isEnd = false;
};

int main () {
    WordDictionary* a = new WordDictionary();
    a->addWord("pad");
    a->addWord("bad");
}

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */