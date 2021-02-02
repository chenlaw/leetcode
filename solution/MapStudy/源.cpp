#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<map>
#include <utility>
#include<unordered_map>
#include<unordered_set>
using namespace std;
int main() {

	unordered_map<string, int> s;
	s.insert(make_pair("123", 3));
	s["happy"] = 4;
	int res= s["happy"];
	cout<<(res);
	unordered_set<int> ss;
	ss.insert(2);
	ss.insert(2);
	ss.insert(4);
	cout << ss.size();


}