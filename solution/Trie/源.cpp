#include<vector>
#include<string>
using namespace std;
class Trie {
public:
    char c;
    vector<Trie*> chirds;
    bool isEnd;
    /** Initialize your data structure here. */
    Trie() {
        chirds = vector<Trie*>(26,NULL);
        isEnd = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* now = this;
        for (char r : word) {
            if (now->chirds[r - 'a'] == NULL) {
                now->chirds[r - 'a'] = new Trie();
                now = now->chirds[r - 'a'];
            }
            else {
                now = now->chirds[r - 'a'];
            }
        }
        now->isEnd = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* now = this;
        for (char r : word) {
            if (now->chirds[r - 'a'] != NULL) {
                now = now->chirds[r - 'a'];
            }
            else {
                return false;
            }
        }
        if (now->isEnd)return true;
        else return false;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* now = this;
        for (char r : prefix) {
            if (now->chirds[r - 'a'] != NULL) {
                now = now->chirds[r - 'a'];
            }
            else {
                return false;
            }
        }
        return true;
    }

};
