#include<string>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


vector<int> findNext(string need) {
	int l = need.size();
	if (need.size() == 0)return {};
	vector<int> next(l);
	next[0] = -1;
	for (int i = 1; i < l; i++) {
		int j = next[i - 1];
		while (j >= 0 && need.at(j + 1) != need.at(i))
			j = next[j];
		if (need.at(j + 1) == need.at(i ))
			next[i] = j + 1;
		else
			next[i] = -1;			
	}
	return next;
}
//needleÎªÄ£Ê½´®£¬
int strStr(string haystack, string needle) {
	int l1 = needle.size();
	int lh = haystack.size();
	vector<int> next = findNext(needle);
	int begin = 0; int progress = -1;
	while (begin <= lh - l1 && progress != l1 - 1) {
		if (haystack.at(begin + progress + 1) == needle.at(progress + 1)) {
			progress++;
		}
		else {
			if (progress == -1) {
				begin++;
			}
			else {
				int j = next[progress];
				begin += progress - j;
				progress = j;
			}
		}
	}
	if (progress == l1-1)
		return begin;
	else
		return -1;
}
int main() {
	string s = "abcaba";
	string s1 = "aba";
	int tes = strStr(s, s1);
}