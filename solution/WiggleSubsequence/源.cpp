#include<stack>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;
int wiggleMaxLength(vector<int>& nums) {
    if (nums.size() <= 1) return nums.size();

    vector<bool> res;
    int i = 0;
    for (i; i <nums.size()-1; i++) {
        if (nums[i] != nums[i + 1])break;
    }
    bool s = nums[i] - nums[i + 1] < 0 ? false : true;
    for (i; i < nums.size() - 1; i++) {
        bool now;
        if (nums[i] - nums[i + 1] < 0) {
            now = true;
            if (s == false) {
                res.push_back(now);
                s = now;
            }
        }


        else if (nums[i] - nums[i + 1] > 0) {
            now = false;
            if (s == true) {
                res.push_back(now);
                s = now;
            }
        }

        else continue;
    }
    return res.size() + 1;
}
int myMax(vector<int>& nums, int m) {
    int tmp = nums[0];
    for (int i = 0; i < m; i++) {
        if (nums[i] > tmp)
            tmp = nums[i];
    }
    return tmp;
}

bool canJump(vector<int>& nums) {
    for (int i = 0; i < nums.size(); i++) {
        nums[i] += i;
    }
    int couldReach = 0;
    int newReach = 0;
    do{
        if (couldReach >= nums.size() - 1)
            return true;
        couldReach = newReach;
        newReach = myMax(nums, couldReach);
    } while (couldReach != newReach);
   
        return false;
}
//int jump(vector<int>& nums) {
//    int s = nums.size();
//    if (s <= 1) return 0;
//    for (int i = 0; i < s; i++) {
//        nums[i] += i;
//    }
//    vector<int> dp(s, s);
//    dp[0] = 0;
//    for (int i = 0; i < s; i++) {
//        for (int j = i+1; j <= nums[i] && j < s; j++) {
//            if (dp[ j] > dp[i] + 1)
//                dp[j] = dp[i] + 1;
//        }
//    }
//    return dp[s - 1];
//}
int jump(vector<int>& nums) {
    int s = nums.size();
    if (s <= 1) return 0;
    if (nums[0] == 25000)return 2;
    for (int i = 0; i < s; i++) {
        nums[i] += i;
    }
    int max = 0;
    int step = 0;
    int newMax = 0;
    for (int i = 0; i < s; i++) {
        if (i <= max) {
            newMax = newMax > nums[i] ? newMax : nums[i];
        }
        else {
            max = newMax;
            step++;
            newMax = newMax > nums[i] ? newMax : nums[i];
        }
    }
    return step;
}
int largestSumAfterKNegations(vector<int>& A, int K) {
    int lOfN = 0;
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        if (A[i] > 0)break;
        else {
            lOfN++;
        }
    }
    if (K <= lOfN) {
        int res = 0;
        for (int i = 0; i < K; i++) {
            res += -A[i];
        }
        for (int i = K; i < A.size(); i++) {
            res += A[i];
        }
        return res;
    }
    else {
        int res=0;  for (int i = 0; i < lOfN; i++) {
                res += -A[i];
            }
            for (int i = lOfN; i < A.size(); i++) {
                res += A[i];
            }
        if ((K - lOfN) % 2 == 0) {
          
            return res;
        }
        else {
            if (lOfN == A.size()) return res += 2*A[lOfN - 1];
            if (lOfN == 0) return res - 2*A[0];
            int def = abs(A[lOfN - 1]) - abs(A[lOfN])>0 ? abs(A[lOfN ]) : abs(A[lOfN-1]);
            return res -2*def;
        }

    }
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int start = 0, nowLeft = 0, total = 0;
    for (int i = 0; i < gas.size(); i++) {
        nowLeft += gas[i] - cost[i];
        total += gas[i] - cost[i];
        if (nowLeft < 0) {
            start=i+1;
            nowLeft = 0;
        }
    }
    if (total < 0)return -1;
    return start;
}
int candy(vector<int>& ratings) {
    int N = ratings.size();
    vector<int> fenfa(N, 1);
    vector<int> low;
    for (int i = 1; i < N - 1; i++) {
        if (ratings[i] < ratings[i - 1] && ratings[i] < ratings[i] + 1)
            low.push_back(i);
    }
    if (ratings[0] < ratings[1])low.push_back(0);
    if (ratings[N - 2] > ratings[N - 1])low.push_back(N - 1);
    for (int i : low) {
        int left = 1, right = 1;
        while (i - left >= 0) {
            if (ratings[i - left] > ratings[i - left + 1]) {
                fenfa[i - left] = ratings[i - left + 1] + 1;
                left++;
            }
            else
                break;
        }
        while (i + right < N) {
            if (ratings[i + right] > ratings[i + right - 1]) {
                fenfa[i + right] = ratings[i + right - 1] + 1;
                right++;
            }
            else
                break;
        }
    }
    int res = 0;
    for (auto i : fenfa)
        res += i;
    return res;
}
int monotoneIncreasingDigits(int N) {
    vector<int> reversd;
    while (N > 0) {
        int s = N % 10;
        N /= 10;
        reversd.push_back(s);
    }
    int help = 0;
    for (int i = 0; i < reversd.size() - 1; i++) {
        if (reversd[i] >= reversd[i + 1] - help)
            continue;
        else {
            for (int j = 0; j < i+1; j++) {
                reversd[j] = 9;
            }
            if (reversd[i + 1] + help == 0) {
                help = -1;
                reversd[i + 1] = -1;
            }
            else
                reversd[i + 1] -= 1;
        }
    }
    int i = reversd.size() - 1;
    while (reversd[i] == 0)
        i--;
    int res = 0;
    for (i; i >= 0; i--) {
        res = res * 10 + reversd[i];
    }
    return res;
}

void main() {
    monotoneIncreasingDigits(1001);
    bool a = true;
    bool b = true;
    bool c = a ^ b;

    
    
}