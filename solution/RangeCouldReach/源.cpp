#include<vector>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool couldInter(int x, int y, int max) {
	int res = 0;
	while (x > 0) {
		res += x % 10;
		x /= 10;
	}
	while (y > 0) {
		res += y % 10;
		y /= 10;
	}
	if (res <= max)
		return true;
	return false;
}
void BFS(int i, int j,int max,deque<pair<int, int>>& hasReached, vector<vector<bool>>& Reached) {
	if (i > 0 && !Reached[i - 1][j]) {
		if (couldInter(i - 1, j, max)) {
			hasReached.push_back(make_pair(i-1,j));
			Reached[i - 1][j] = true;
		}
	}
	if (i + 1 < Reached.size() && !Reached[i + 1][j]) {
		if (couldInter(i +1, j, max)) {
			hasReached.push_back(make_pair(i +1, j));
			Reached[i + 1][j] = true;
		}
	}
	if (j > 0 && !Reached[i][j - 1]) {
		if (couldInter(i , j-1, max)) {
			hasReached.push_back(make_pair(i, j-1));
			Reached[i ][j-1] = true;
		}
	}
	if (j +1<Reached[0].size() && !Reached[i][j + 1]) {
		if (couldInter(i, j + 1, max)) {
			hasReached.push_back(make_pair(i, j + 1));
			Reached[i][j + 1] = true;
		}
	}
}
int movingCount(int threshold, int rows, int cols)
{
	vector<vector<bool>> Reached(rows, vector<bool>(cols,false));
	deque<pair<int, int>> hasReached;
	if (threshold < 0)
		return 0;
	Reached[0][0] = true;
	hasReached.push_back(make_pair(0, 0));
	BFS(0, 0, threshold,hasReached, Reached);
	while (!hasReached.empty()) {
		pair<int, int> now = hasReached.front();
		hasReached.pop_front();
		BFS(now.first, now.second, threshold,hasReached, Reached);
	}
	int res = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (Reached[i][j]) {
				res += 1;
			}
		}
	}
	return res;
}
int main() {
	auto a = movingCount(5, 10, 10);
}