#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
	unordered_map<int, int> count;
	for (int c : nums) {
		count[c]++;
	}
	priority_queue<pair<int, int>> q;
	for (auto c : count) {
		q.emplace(c.second, c.first);
	}
	vector<int> res;
	for (int i = 0; i < k; i++) {
		res.push_back(q.top().second);
		q.pop();
	}
}