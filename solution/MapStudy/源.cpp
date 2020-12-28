#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<map>
#include <utility>
#include<unordered_map>
using namespace std;
int main() {
	unordered_map<string, int> s;
	s.insert(make_pair("123", 3));
	s["happy"] = 4;
	int res= s["happy"];
	cout<<(res);
}