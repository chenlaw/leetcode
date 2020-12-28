#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<list>

using namespace std;
int firstUniqChar(string s) {
	int res[26] = {0};
	for (char c : s)
	{
		res[c - 'a'] += 1;
	}
	for (int i = 0; i < s.length(); i++)
		if (res[s.at(i) - 'a'] < 1)
			return i;
	return -1;


}
int main() {
	string s = "hello";
	char r = firstUniqChar(s);
	int i = 1;
}