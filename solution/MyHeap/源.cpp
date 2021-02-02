#include<vector>
using namespace std;
void transfom(vector<int>& v) {
	int l = v.size();
	int j = l / 2;
	for (j; j >= 0; j--) {
		int tmp = j;
		while (2*tmp+1 < l) {
			if (v[2 * tmp + 1] > v[tmp])
				swap(v[tmp], v[2 * tmp + 1]);
		}
	}
}