#include<stack>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;
vector<int> path;
vector<vector<int>>res;
void combine(int begin, int end, int k) {
    if (k == 0) {
        res.push_back(path);
        return;
    }
    if (begin > end)return;
    for (begin; begin <= end; begin++) {
        path.push_back(begin);
      
        combine(begin + 1, end, k-1);
        path.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    res.clear();
    path.clear();
    combine(1, n, k);
    return res;
}
void combine(int begin, int end, int k, int sum) {
    if (sum < 0)return;
    if (k == 0) {
        if (sum == 0)
            res.push_back(path);
        return;
    }

    if (begin > end)return;
    for (begin; begin <= end - k+1; begin++) {
        path.push_back(begin);
        combine(begin + 1, end, k - 1, sum - begin);
        path.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    path.clear();
    res.clear();
    combine(1, 9, k, n);
    return res;
}
int main() {
    vector<vector<int >> n = combinationSum3(9, 45);
    string s = "asd";
    s.size();
    n[n.size()-1]
}