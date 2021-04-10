#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int l1 = 0, h1 = 0;
    int h2 = matrix.size() - 1;
    int l2 = matrix[0].size() - 1;
    vector<int> res;
    while (l1 <= l2 && h1 <= h2) {
        for (int j = l1; j <= l2; j++)
            res.push_back(matrix[h1][j]);
        h1++;
        for (int i = h1; i <= h2; i++)
            res.push_back(matrix[i][l2]);
        l2--;
        for (int j = l2; j >= l1; j--)
            res.push_back(matrix[h2][j]);
        h2--;
        for (int i = h2; i >= h1; i--)
            res.push_back(matrix[i][l1]);
        l1++;
    }
    return res;
}
int main() {
    vector<vector<int>> v(3, vector<int>(4));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            v[i][j] = i * 4  + j;
        }
    }
    spiralOrder(v);
}