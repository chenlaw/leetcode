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

int main() {
	int N, M;
	cin >> N >> M;
	vector<int> yinsu(M+1);
	for (int i = 2; i <= M; i++) {
		while (M % i == 0) {
			yinsu[i]++;
			M /= i;
		}
	}
	vector<vector<int>> dp(N + 1, vector<int>(yinsu.size()));
	vector<int> res(yinsu.size());
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j <= i; j++) {
			if (i % j == 0) {
				for (int k = 0; k < yinsu.size(); k++) {
					if (k == j)
						dp[i][k] = dp[i / j][k] + 1;
					else
						dp[i][k] = dp[i / j][k];
				}
				break;
			}
		}
		
	}
	
	int m = INT_MAX;
	for (int i = 2; i < yinsu.size(); i++) {
		if (yinsu[i] != 0) {
			int tmp = 0;
			for (int j = 0; j < dp.size(); j++)
				tmp += dp[j][i];
			m = min(m, tmp / yinsu[i]);
		}
	}
	cout << m;
}