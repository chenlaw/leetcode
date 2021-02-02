#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
pair<int, int> getP(const string& s, int i, int j) {
    int l = s.size();
    while (0 <= i && j < l && s.at(i) == s.at(j)) {
        i--; j++;
    }
    return pair<int, int>(i + 1, j - 1);
}
string longestPalindrome(string s) {
    int* a = new int(5);
    int start = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        pair<int, int> res = getP(s, i, i);
        if (res.second - res.first > end - start) {
            end = res.second;
            start = res.first;
        }
        res = getP(s, i, i + 1);
        if (res.second - res.first > end - start) {
            end = res.second;
            start = res.first;
        }
    }
    delete a;
    return s.substr(start, end - start + 1);
}

int main() {
    int i = 2;
    int &j = 5;
    int && f = i * 2;
    string s = "bcbbd";
    string rs = longestPalindrome(s);
   
}