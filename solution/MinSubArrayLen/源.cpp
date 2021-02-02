#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<unordered_set>
#include<unordered_map>
using namespace std;
//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。



vector<vector<int>> largeGroupPositions(string s) {
	vector<vector<int>> v;
	int i = 0, j = 1;
	int l = 3;
	char tmp = s.at(i);
	if (s.length() < 3)
		return v;
	s += '1';
	while (j < s.length()) {
		if (s.at(j) != tmp) {
			if (j - i >= l) {
				v.push_back(vector<int>{ i, j - 1});
			}
			i = j;
			tmp = s.at(i);
			j = i + 1;
		}
		j++;
	}
	return v;
}
//双指针法O(N)
int minSubArrayLen(int s, vector<int>& nums) {
	int l = nums.size();
	int begin = 0, end = 0;
	int min = INT_MAX;
	int sum = 0;
	while(end<l) {
		sum += nums[end];
		while (sum >= s) {
			sum -= nums[begin];
			
			min = min < end - begin + 1 ? min : end - begin + 1;
			begin++;		
		}
		end++;
	}
	if (min== INT_MAX)
		min = 0;
	return min;
}
int main() {
	string s = "abcdddeeeeaabbbcd";
	vector<vector<int>> v=largeGroupPositions(s);
	vector<int> g = {3,4,5,1,2};
	auto c=max(g.begin(), g.end());
	unordered_set<int> cs;
	cs.emplace(3);
	auto r=cs.find(-1);

}