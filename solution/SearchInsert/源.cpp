#include<vector>
#include<stack>
#include<string>
#include <algorithm>
using namespace std;
int searchInsert(vector<int>& nums, int target) {
	int begin = 0;
	int end = nums.size() - 1;
	int mid = (begin + end) / 2;
	while (begin <= end) {
		if (nums[mid] == target)
			return mid;
		else if (nums[mid] < target)
			begin = mid+1;
		else
			end = mid-1;
		mid = (begin + end) / 2;
	}
	return begin ;
}
int main() {
	int target = 0;
	vector<int> v = { 1,3,5,6 };
	int pos = searchInsert(v, target);
	string s = "AsdfA";
	s=s.substr(0, 0);
}