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
bool isBalanced(int i) {
	int a = 0;
	int b = 0;
	int weishu = 0;
	while (i != 0) {
		if (weishu % 2 == 0)
			a += i % 10;
		else
			b += i % 10;
		weishu++;
		i /= 10;
	}
	return a == b;
}
int main() {
	int L, R;
	cin >> L >> R;
	//±©Á¦
	int couldWei = 0;
	
	int res = 0;
	for ( L; L <= R; L++) {
		if (isBalanced(L))
			res++;
	}
}