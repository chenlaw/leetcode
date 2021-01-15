#include<vector>
using namespace std;
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
	int could = 0;
	int help = 0;
	int thi = 0;
	int l = flowerbed.size();
	for (int i = 0; i < l; i++) {
		if (flowerbed[i] == 1) {
			help -= 1;
			if (help > 0)
				thi = (help-1) /2 + 1;
			could += thi;
			thi = 0;
			help = -1;		
		}
		else {
			help += 1;
		}
	}
	if (help > 0)
		thi = (help-1) / 2 + 1;
	could += thi;
	return could >= n;
}