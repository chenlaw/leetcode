#include<stack>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;
//vector<string> path;
//vector<vector<string>> res;
//vector<vector<bool>> dp;
//void helpDP(string& s, int i, int j) {
//    while (i >= 0 && j < s.length() && s.at(i) == s.at(j)) {
//        dp[i][j] = true;
//        i--; j++;
//    }
//}
//void dfs(string& s, int begin, int end) {
//    if (begin > end) {
//        res.push_back(path);
//        return;
//    }
//    for (int i = 0; begin + i <= end; i++) {
//        if (dp[begin][begin + i]) {
//            path.push_back(s.substr(begin, i+1));
//            dfs(s, begin + i + 1, end);
//            path.pop_back();
//        }
//
//    }
//}
//vector<vector<string>> partition(string s) {
//    int l = s.length();
//    dp = vector<vector<bool>>(l, vector<bool>(l));
//    for (int i = 0; i < s.length(); i++) {
//        helpDP(s, i, i);
//        helpDP(s, i, i + 1);
//    }
//    dfs(s, 0, s.length() - 1);
//    return res;
//}
//vector<string> path;
//vector<string> res;
//bool isValid(string& s, int begin, int end) {
//    if (end > s.length()) return false;
//    if (end == begin)return true;
//    if (end - begin == 1 && s.at(begin) != '0')return true;
//    if (end - begin == 2) {
//        if (s.at(begin) != '0') {
//            int tmp = 0;
//            tmp = (s.at(begin) - '0') * 100 + (s.at(begin + 1) - '0') * 10 + s.at(begin + 2) - '0';
//            if (tmp < 255)return true;
//       }
//    }
//    return false;
//
//}
//void dfs(string& s, int begin, int end, int n) {
//    if (n == 0) {
//        if (begin > end)res.push_back(path[path.size() - 1]);
//        return;
//    }
//    if (begin > end && n != 0)return;
//    for (int i = 0; i < 3; i++) {
//        if (begin + i > end)break;
//        if (isValid(s, begin, begin + i)) {
//            if (!path.empty())
//                path.push_back(path[path.size() - 1] + "." + s.substr(begin, i + 1));
//            else
//                path.push_back(s.substr(begin, i + 1));
//            dfs(s, begin + i + 1, end, n - 1);
//            path.pop_back();
//        }
//    }
//}
//vector<string> restoreIpAddresses(string s) {
//
//    dfs(s, 0, s.length() - 1, 4);
//    return res;
//}
vector<int> path;
vector<vector<int>> res;
void dfs(vector<int>& candidates, int i, int target) {
    if (target == 0) {
        res.push_back(path);
        return;
    }
    for (i; i < candidates.size(); i++) {
        if (path.size() != 0)
            if (candidates[i] >= path[path.size() - 1]) {
                path.push_back(candidates[i]);
                dfs(candidates, i + 1, target - 1);
                path.pop_back();
            }
            else {
                path.push_back(candidates[i]);
                dfs(candidates, i + 1, target - 1);
                path.pop_back();
            }
        while (i < candidates.size() - 1 && candidates[i + 1] == candidates[i])i++;
    }

}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    for (int i = 2; i <= nums.size(); i++) {
        dfs(nums, 0, i);
    }
    return res;
}
int main() {
    vector<int> s = { 4, 6, 7, 7
    };
    unordered_map<int, int> um;
    move
    auto m = findSubsequences(s);
}