#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	int len = nums.size();

	for (int i = 0; i < len - 3; i++) {
		if (i > 0 && nums[i - 1] == nums[i])
			continue;
		int j = i + 1;
		int k = len - 1;
		int now = nums[i];
		while (j != k) {
			if (j > i + 1 && nums[j - 1] == nums[j]) {
				j++;
				continue;
			}
			
			int tmp = now + nums[j] + nums[k];
			if (tmp == 0) {
				res.push_back({ nums[i],nums[j],nums[k] });
				j++;
				continue;
			}
			else if (tmp <= 0) {
				j++;
				continue;
			}
			else {
				k--;
				continue;
			}
		}
	}
	return res;
}
int main() {
	vector<int> nums = {
};
	vector<vector<int>> r=threeSum(nums);
}