#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
using namespace std;
vector<string> split(string s) {
    vector<string> v;
    string r = "";
    for (int i = 0; i < s.length(); i++) {
        if (s.at(i) != ' ' && s.at(i) != '.')
            r += s.at(i);
        else {
            if (r != "")
                v.push_back(r);
            r = "";
        }
    }
    return v;
}
string ReverseSentence(string str) {
    vector<string> s = split(str);

    string str1 = "";
    if (s.size() == 0)
        return str1;
    for (int i = s.size() - 1; i > 0; i--) {
        str1 = str1 + s[i] + " ";
    }
    str1 += s[0] + ".";
    return str1;
}

int main() {
    string s = "student. a am I";
    string res = ReverseSentence(s);
}