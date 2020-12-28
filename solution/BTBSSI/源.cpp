#include<vector>

using namespace std;
int maxProfit(int k, vector<int>& prices) {
	vector<int> profils;
	for (int i = 0; i < prices.size()-1; i++) {
		profils.push_back(prices[i + 1] - prices[i]);
	}
	
}