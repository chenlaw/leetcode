#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<unordered_map>
#include<iomanip>
using namespace std;
int lengthOfLongestSubstring(string s) {
	unordered_map<char, int> alphas;
	int l = s.length();
	int begin = 0;
	int len = 0;
	for (int i = 0; i < l; i++) {
		if (alphas.find(s.at(i))!=alphas.end()) {
			len = max(len, i - begin);
			begin = alphas[s.at(i) ] + 1;
		}
		alphas[s.at(i)] = i;
	}
	len = max(len, l - begin);
	return len;
}
int main() {
	lengthOfLongestSubstring("abba");
	stack<int> ms;
	stack<double> ws;
	int m0, w0;
	cin >> m0 >> w0;
	ms.push(m0);
	ws.push(w0);
	int orders;
	cin >> orders;
	int tmp = 0;
	for (int i = 0; i < orders; i++) {
		string order;
		cin >> order;
		if (order == "B") {
			if (tmp != 0) {
				ms.pop();
				ws.pop();
				tmp--;
			}
			
		}
		else {
			int mi, wi;
			cin >> mi >> wi;
			int mnow = mi + ms.top();
			double wnow = ((double)(mi * wi) / 100 + (double)(ms.top() * ws.top()) / 100)  * 100/ (double)mnow;
			ms.push(mnow);
			ws.push(wnow);
			tmp++;
		}
		cout << ms.top() << " " << setiosflags(ios::fixed) << setprecision(5) << ws.top()<<endl;
	}
}