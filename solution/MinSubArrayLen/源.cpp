#include<vector>
using namespace std;
//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。

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
	int s = 7;
	vector<int> nums = { 2, 3, 1, 2, 4, 3 };
	int min = minSubArrayLen(s, nums);
}