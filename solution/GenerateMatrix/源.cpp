#include<vector>;
using namespace std;

vector<vector<int>> generateMatrix(int n) {
	int l = 0,r=n-1,u=0,d=n-1;
	vector<vector<int>> res(n, vector<int>(n));
	int end = n * n;
	int num = 0;
	while (num < end) {
		for (int i = l; i <=r; i++)
			res[u][i] = num++;
		u++;
		for (int j = u; j <= d; j++)
			res[j][r] = num++;
		r--;
		for (int i = r; i >= l; i--)
			res[d][i] = num++;
		d--;
		for (int i = d; i >= u; i--)
			res[i][l] = num++;
		l++;
	}
	return res;
}
int main() {
	int s = 3;
	vector<vector<int>> r = generateMatrix(s);
}