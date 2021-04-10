#include<stack>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<numeric>
using namespace std;
int findIn(vector<int>& v, int c) {
    int end = v.size();
    int begin = 0;
    int m = end / 2;
    while (begin < end) {
        if (c <= v[m]) {
            end = m;
            m = (end + begin) / 2;
        }
        else {
            begin = m+1;
            m = (end + begin) / 2;
        }
    }
    return m;
}
int sum(vector<int> &v, int begin, int end) {
    int res = 0;
    while (begin <=end) {
        res += v[begin];
        begin++;
    }
    return res;
}
int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {

    int m = 0;
    int end = customers.size() - 1;
    int total = 0;
    for (int i = 0; i < customers.size() - X; i++) {
        if (grumpy[i] == 0)total += customers[i];
    }
    for (int i = 0; i < X; i++)total += customers[i + customers.size() - X];
    for (int end = customers.size() - 2; end - X + 1 >= 0; end--) {
        int tmp = 0;
        if (grumpy[end + 1] == 1)tmp -= customers[end + 1];
        if (grumpy[end - X + 1] == 1)tmp += customers[end - X + 1];
        if (tmp > 0)total += tmp;
    }

    return total;
}
void main() {
    vector<int>a = { 1,0,1,2,1,1,7,5};
    vector<int>b = { 0,1,0,1,0,1,0,1 };
    vector<int> c = { 5,8 };
    vector<int> d = { 0,1 };
    int r = findIn(c, 2);
    maxSatisfied(a, b, 3);
}