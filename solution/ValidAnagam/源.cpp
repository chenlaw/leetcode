#include<string>
#include<vector>
using namespace std;
bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;
    int s1[26] = { 0 }, t1[26] = { 0 };
    int l = s.size();
    for (auto s0 = s.begin(), t0 = t.begin(); s0 != s.end(); s0++, t0++) {
        s1[*s0 - 'a']++;
        t1[*t0 - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (s1[i] != t1[i])
            return false;
    }
    return true;
}