#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<queue>
using namespace std;
//�������ȶ��У�ȷ��ÿ�ζѶ���i-k��
//vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//	int n = nums.size();
//	priority_queue < pair<int, int>> q;
//	for (int i = 0; i < k; i++) {
//		q.push({ nums[i],i });
//	}
//	vector<int> res;
//	for (int i = k; i < n; i++) {
//		q.emplace( nums[i ],i  );
//		while (q.top().second < i - k)
//			q.pop();
//		res.push_back(q.top().first);
//
//	}
//	return res;
//}
