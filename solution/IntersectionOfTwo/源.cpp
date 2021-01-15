#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	unordered_set<int> n1(nums1.begin(),nums1.end());
	unordered_set<int> n2(nums2.begin(), nums2.end());
	vector<int> res;
	for (auto& a : n1) {
		if (n2.count(a) == 1)
			res.push_back(a);
	}
	return res;
}