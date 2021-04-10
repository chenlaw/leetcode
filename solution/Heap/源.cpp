#include<stack>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
void shift(vector<int>& v, int i) {
    int j = (i - 1) / 2;
    while (i > 0) {
        if (v[j] < v[i]) {
            swap(v[i], v[j]);
            i = j;
            j = (j - 1) / 2;
        }
        else return;
    }

}
void down(vector<int>& v) {
    int i = 0;
    int l = v.size();
    while (2 * i + 1 < l) {
        int tmp = 0;
        int j = 2 * i + 1;

        if (2 * i + 2 < l) {
            j = v[2 * i + 1] > v[2 * i + 2] ? 2 * i + 1 : 2 * i + 2;
        }
        if (v[i] < v[j]) {
            swap(v[i], v[j]);
            tmp = j;
        }
        if (tmp == 0) break;
        i = tmp;
    }
}
vector<int> getLeastNumbers(vector<int>& arr, int k) {
    if (k == 0)return {};
    vector<int> v(k);
    int l = arr.size();
    for (int i = 0; i < k; i++) {
        v[i] = arr[i];
        shift(v, i);
    }
    for (int i = k; i < l; i++) {
        if (arr[k] < v[0]) {
            v[0] = arr[k];
            down(v);
        }
    }
    return v;
}
int main() {
    vector<int> v = { 0,1,2,3,4,0,3,3,8,1,4,6,2,8,8,15,10,0,9,9,1,2,17,8,17 ,25,18,18,16,13,18,29,2,3,32,2,26,23,18,8,34,8,11,36,36,39,46,30,21,25 ,21,14,41,10,31,55,45,16,33,47,4,52,59,60,1,43,42,10,12,56,12,27,22,52,38 ,12,41,42,71,5,42,76,8,3,31,65,11,29,28,68,33,50,73,87,22,68,31,1,38,89 };
    auto c = getLeastNumbers(v, 60);
}