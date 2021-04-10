#include<stack>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

int reverse(vector<int>& A, int K, int begin) {
    int res = 0;
    for (int i = 0; i < K; i++) {
        if (res == 0) {
            if (A[i + begin] == 1)
                res = i + begin;
        }
        A[i + begin] = A[i + begin] ^ 1;
    }
    if (res == 0)return begin + K ;
    return res;
}
int minKBitFlips(vector<int>& A, int K) {
    int l = A.size();
    int res = 0;
    for (int i = 0; i <= l - K;) {
        if (A[i] == 0) {
            i = reverse(A, K, i);
            res += 1;
        }
        else {
            i++;
        }

    }
    for (int i = l - K + 1; i < l; i++) {
        if (A[i] == 0)return -1;
    }
    return res;
}
//int longestOnes(vector<int>& A, int K) {
//    int l = A.size();
//    vector<vector<int>> dp(l + 1, vector<int>(K+1, 0));
//    int m = 0;
//    for (int i = 0; i < l; i++) {
//        for (int j = 0; j <= K; j++) {
//            if (A[i] == 1)
//                dp[i + 1][j] = dp[i][j] + 1;
//            else
//                dp[i + 1][j] = j != K ? dp[i][j + 1] + 1 : 0;
//            m = max(m, dp[i+1][j]);
//        }
//    }
//    return m;
//}
int findByOrder(const vector<int>& A, int n) {
    int begin = 0;
    int end = A.size() - 1;
    int m = begin + end / 2;
    while (begin < end) {
        if (A[m] >= n) {
            end = m;
            m = (begin + end) / 2;
        }
        else {
            begin = m + 1;
            m = (begin + end) / 2;
        }
    }
    return m;
}
int longestOnes(vector<int>& A, int K) {
    int l = A.size();
    vector<int> v(l, 0);
    v[0] = 1 - A[0];
    for (int i = 1; i < l; i++) {
        v[i] = v[i - 1] + 1 - A[i];
    }
    int m = 0;
    for (int r = l - 1; r >= 0;r--) {
        int now = v[r];
        int left = findByOrder(v, now - K);
       
        m = max(m, r - left );
        if (left == 0)return m;
        //r = findByOrder(v, now - 1);
    }
    return m;
}
int myAtoi(string s) {
    int fuhao = 1;
    int i = 0;
    for (i; i < s.length(); i++) {
        char c = s.at(i);
        if (c != ' ') {
            if (c == '-') {
                fuhao = -1;
                i++;
                break;
            }
            else if (c < '0' || c>'9')
                return 0;
            else break;
        }
    }
    long res = 0;
    for (i; i < s.length(); i++) {
        char c = s.at(i);
        if (c < '0' || c>'9')break;
        res = res * 10 + c - '0';
    }
    res *= fuhao;
    if (res > 2 ^ 31 - 1)return INT_MAX;
    if (res < (-(2 ^ 31)))return INT_MIN;
    return res;
}
string mergeAlternately(string word1, string word2) {
    int l1 = word1.length();
    int l2 = word2.length();
    int l = min(l1, l2);
    string s = "";
    for (int i = 0; i < l; i++) {
        s += word1.at(i) + word2.at(i);
    }
    if (l1 > l)s = s + word1.substr(l, l1 - l);
    if (l2 > l)s = s + word2.substr(l, l2 - l);
    return s;
}
int longestSubarray(vector<int>& nums, int limit) {
   // sort(nums.begin(), nums.end());
    int l = nums.size();
    int maxL = 0;
    int begin = 0;
    int end = 0;
    for (end; end < l;) {
        if (abs(nums[end] - nums[begin]) <= limit)
            end++;
        else {
            maxL = max(maxL, end - begin );
            while(abs(nums[end]-nums[begin])>limit)
            begin++;
        }
    }
    if (abs(nums[end-1] - nums[begin]) <= limit)
        maxL = max(maxL, end - begin );
    return maxL;
}
bool couldReach(vector<vector<char>>& board, vector<vector<bool>>& could, int h, int w, int i, int j, string& word, int k) {
    if (board[i][j] == word.at(k) && could[i][j]) {
        if (k == word.length() - 1)return true;
        could[i][j] = true;
        bool res = true;
        if (i - 1 >= 0 && couldReach(board, could, h, w, i - 1, j, word, k + 1))return true;
        if (i + 1 < h && couldReach(board, could, h, w, i + 1, j, word, k + 1))return true;
        if (j - 1 >= 0 && couldReach(board, could, h, w, i, j - 1, word, k + 1))return true;
        if (j + 1 < w && couldReach(board, could, h, w, i, j + 1, word, k + 1))return true;
        could[i][j] = false;
        return false;
    }
    return false;

}
bool exist(vector<vector<char>>& board, string word) {
    int h = board.size();
    int w = board[0].size();
    vector<vector<bool>> could(h, vector<bool>(w, false));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (couldReach(board, could, h, w, i, j, word, 0))
                return true;
        }
    }
    return false;
}
vector<int> exchange(vector<int>& nums) {
    int a = 0, b = 0;
    int l = nums.size();
    while (b < l) {
        if (nums[b] % 2 == 1) {
            while (a < b && nums[a] % 2 == 1)
                a++;
            swap(nums[a], nums[b]);
            b++;

        }
        b++;
    }
    return nums;
}
int main() {
    vector<int> v = { 2,16,3,5,13,1,16,1,12,18,11,8,11,11,5,1 };
    exchange(v);
    /*vector<vector<char>> vs = { {"a","b"},{"c","d"} };
    exist(vs, "abcd");
    vector<int> v = { 1,5,6,7,8,10,6,5,6};
    longestSubarray(v, 4);
    string s = mergeAlternately("asd", "zxcv");*/
    /*vector<int> v = { 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
    int r = longestOnes(v, 3);
    int n = A.size();*/
    myAtoi("47");
   /* vector<int> P(n + 1);
    for (int i = 1; i <= n; ++i) {
        P[i] = P[i - 1] + (1 - A[i - 1]);
    }

    int ans = 0;
    for (int right = 0; right < n; ++right) {
        int left = lower_bound(P.begin(), P.end(), P[right + 1] - K) - P.begin();
        ans = max(ans, right - left + 1);
    }
    return ans;*/

}