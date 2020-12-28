#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<map>
#include <utility>
#include<unordered_map>
using namespace std;
int main() {
<<<<<<< HEAD
	unordered_map<string, int> s;
	s.insert(make_pair("123", 3));
	s["happy"] = 4;
	int res= s["happy"];
	cout<<(res);
=======
	unordered_map<int, int> s;
	s.insert(1, 3);
	s.insert(2,4);
	auto m=s.find(2);
>>>>>>> 244b5e8aafcfb6bb265d595d207a78fee59a89f2
}