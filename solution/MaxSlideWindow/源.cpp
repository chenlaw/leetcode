#include<vector>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
vector<int> maxInWindows(const vector<int>& num, unsigned int size)
{
	int s = num.size();
	vector<int> v(s, -1);
	if (s < size)
		return v;
	v[0] = 0;
	for (int i = 1; i < size; i++) {
		if (num[i] > num[v[i - 1]]) {
			v[i] = i;
		}
		else {
			v[i] = v[i - 1];
		}
	}
	for (int i = size; i < s; i++) {
		int max = i;
		for (int j = 1; j < size; j++) {
			if (num[i] >= num[v[i - j]]) {
				v[i] = i;
				break;
			}
			else if (i - v[i - j] < size) {
				v[i] = v[i - j];
				break;
			}
			else {
				if (num[i - j] > num[max])
					max = i - j;
			}
		}
		if (v[i] == -1)
			v[i] = max;
	}
	vector<int> res;
	for (int j = size - 1; j < s; j++) {
		res.push_back(num[v[j]]);
	}
	return res;
}
int main() {
	vector<int> v = { 2, 3, 4, 2, 6, 2, 5, 1 };
	vector<int> r = maxInWindows(v, 3);
	cout << r[0];
}