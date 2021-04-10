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
	int k;
	string s;
	cin >> k;
	cin >> s;
	int sl = s.length();
	if (sl % k != 0) {
		cout << -1;
		return 0;
	}
	else {
		int count = sl / k;
		string res = "";
		vector<int> chars(26, 0);
		int diff = 0;
		int i = 0;
		for (i; i < sl; i++) {
			res += s.at(i);
			if (chars[s.at(i) - 'a'] == 0) {
				diff += 1;
				chars[s.at(i) - 'a']=k-1;
			}
			else {
				chars[s.at(i) - 'a']--;
			}
			if (diff == count)break;
		}
		bool couldrea = true;
		for (i = i + 1; i < sl; i++) {
			for (int j = s.at(i) - 'a'; j >= 0; j--) {
				if (chars[j] >= 0 && j < s.at(i) - 'a') {
					res += 'a' + j;
					break;
				}
			}
		}

		cout<<res;
	}
}
bool isHappy(int n) {
	vector<int> v(10);
	while (n != 0) {
		v[n % 10]++;
		n = n / 10;
	}
	int res = 0;
	for (int i = 2; i < 10; i++) {
		if (v[i] != 0)res++;
	}
	return res <= 1;
}
//int n;
//cin >> n;
//vector<int> v(n);
//for (int i = 0; i < n; i++) {
//	cin >> v[i];
//}
//int maxl = 0;
//bool isZOrder = true;
//bool isSorder = false;
//for (int i = 0; i < n - 1; i++) {
//	if (v[i] > v[i + 1])
//		isZOrder = false;
//	if (v[i] < v[i + 1])
//		isSorder = false;
//}
//if (isZOrder || isSorder) {
//	cout << 0;
//	return 0;
//}
//for (int i = 1; i < n - 1; i++) {
//	int tmp = v[i];
//	int tmpl = 0;
//	for (int j = i; j > 0; j--) {
//		if (v[j] > v[j - 1])tmpl++;
//		else break;
//	}
//	for (int j = i; j < n - 1; j++) {
//		if (v[j] > v[j + 1])tmpl++;
//		else break;
//	}
//	tmpl += 1;
//	maxl = max(maxl, tmpl);
//}
//cout << maxl;