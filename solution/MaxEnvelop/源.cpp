#include<stack>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int maxEnvelopes(vector<vector<int>>& envelopes) {
	sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b) {
		if (a[0] == b[0])return a[1] > b[1];
		else return a[0] < b[0];
		});
	vector<int> dp(envelopes.size(),1);
	dp[0] = 1;int ma = 1;
	for (int i = 1; i < envelopes.size(); i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (envelopes[i][1] > envelopes[j][1])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ma = max(ma, dp[i]);
	}
	return ma;

}
vector<int> nextGreaterElements(vector<int>& nums) {
	int n = nums.size();
	stack<int> s;
	vector<int> v(n, -1);
	for (int i = 0; i < 2 * n; i++) {
		int now = nums[i % n];
		while (!s.empty() && now > nums[s.top() % n]) {
			v[s.top() % n] = (i % n);
			s.pop();
		}
		s.push(i % n);
	}
	return v;

}
void isHui(string& s, vector<vector<bool>>& dp, int i, int j) {
	while (i >= 0 && j < s.length() && s.at(i) == s.at(j)) {
		dp[i][j] = true;
		i--; j++;
	}
}
string removeDuplicates(string s) {
	int n = s.length();
	vector<vector<bool>> dp;
	for (int i = 0; i < n; i++) {
		isHui(s, dp, i, i + 1);
	}
	string res = "";
	for (int i = 0; i < n;) {
		bool a = false;
		int j = n - 1;;
		for (j; j > i; j--) {
			if (dp[i][j]) {
				i = j + 1;
				a = true;
				break;
			}
		}
		if (!a) {
			res += s.at(i);
			i++;
		}
	}
	return res;
}
int main() {
	//vector<vector<int>> te;
	//te.push_back({5,4 });
	//te.push_back({ 6,4 });
	//te.push_back({ 6,7 });
	//te.push_back({ 2,3 });
	//maxEnvelopes(te);
    //vector<int> tes = { 5,4,3,2,1 };
    //nextGreaterElements(tes);
	string s = "abbac";
	removeDuplicates(s);
}