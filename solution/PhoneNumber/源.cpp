#include<stack>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;
vector<string> path;
vector<string> res;
vector<string> board = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
void dfs(string digits, int begin, int end) {
    if (begin > end) {
        res.push_back(path[path.size() - 1]);
    }
    else {
        for (char c : board[digits[begin]]) {
            path.push_back(path[path.size() - 1] + c);
            dfs(digits, begin + 1, end);
            path.pop_back();
        }
    }
}
vector<string> letterCombinations(string digits) {

    res.clear();
    path = { "" };
    int l = digits.length();
    if (l == 0)return {};
    dfs(digits, 0, l - 1);
    return res;
}
int main() {
    vector<string> s = letterCombinations("23");
}