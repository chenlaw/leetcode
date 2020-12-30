#include<vector>
using namespace std;
int removeElement(vector<int>& nums, int val) {
	int l = nums.size();
	int j = 0;
	for (int i = 0; i < l; i++) {
		if (nums[i] == val)
			continue;
		nums[j] = nums[i];
		j++;
	}
	return   j;
}
int main() {
	int target = 2;
	vector<int> v = { 0, 1, 2, 2, 3, 0, 4, 2 };
		;
	int pos = removeElement(v, target);
}