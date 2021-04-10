#include<stack>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int find(string& s, char c) {
    int l = s.length() - 1;
    if (c < s.at(0))return -1;
    int begin = 0;
    int end = l;
    int m = end / 2;
    while (begin <= end) {
        if (c == s.at(m))return m;
        if (c < s.at(m)) {
            end = m - 1;
            m = (begin + end) / 2;
        }
        else {
            begin = m + 1;
            m = (begin + end) / 2;
        }

    }
    return -2;
}
vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
    int l = puzzles.size();
    sort(puzzles.begin(), puzzles.end());
    vector<vector<bool>> Valid(l, vector<bool>(26));
    for (int i = 0; i < l; i++) {
        for (auto& c : puzzles[i]) {
            Valid[i][c - 'a'] = true;
        }
    }
    for (int i = 0; i < words.size(); i++) {
        vector<bool> v(26);
        for (auto& c : words[i]) {
            v[c - 'a'] = true;
        }
        string s;
        for (int i = 0; i < 26; i++)
            if (v[i]) {
                char c = 'a' + i;
                s += c;
            }
        words[i] = s;
    }
    sort(words.begin(), words.end());
    vector<int> res(l);
    for (int i = 0; i < l; i++) {
        int count = 0;
        for (string& s : words) {
            bool isRes = true;
            int loc = find(s, puzzles[i].at(0));
            if (loc == -1)break;
            if (loc == -2)continue;
            for (char& c : s) {
                if (!Valid[i][c - 'a']) {
                    isRes = false;
                    break;
                }

            }
            count = isRes ? count + 1 : count;
        }
        res.push_back(count);
    }
    return res;
}
int main() {
    vector<string> s = { "aaaa","asas","able","ability","actt","actor","access" };
    vector<string> v = { "aboveyz","abrodyz","abslute","absoryz","actresz","gaswxyz" };
    auto c = findNumOfValidWords(s, v);
}