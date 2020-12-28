#include<vector>
#include<stack>
#include <algorithm>
using namespace std;
int main() {
	vector<int> v = { 2,3,4,5,1,-2 };
	sort(v.begin(), v.end());
	v.erase(v.begin());
}