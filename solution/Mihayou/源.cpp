#include<iomanip>
#include<string>
#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<unordered_map>
#include<iomanip>
using namespace std;
struct game {
	int time;
	int val;
};
bool greatThan(game a, game b) {
	if (a.time < b.time)
		return true;
	else if (a.time == b.time)
		return a.val > b.val;
	else
		return false;
}
int main() {
	int n;//测试用例组数
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;//游戏总数
		vector<game> games(m);
		for (int i = 0; i < m; i++)
			cin >> games[i].time;
		for (int i = 0; i < m; i++)
			cin >> games[i].val;
		sort(games.begin(), games.end(), greatThan);
		int nowTime = 0;
		int res = 0;
		for (auto& ga : games) {
			if (ga.time > nowTime)
				res += ga.val;
			else
				res -= ga.val;
			nowTime++;
		}
		cout << res << endl;
	}
}