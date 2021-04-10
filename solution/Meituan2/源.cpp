#include<iostream>
#include<math.h>
#include<iomanip>
#include<string>
#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;
int main() {
    int m, n;
    cin >> n >> m;
    if (m <= 2) {
        cout << m;
        return 1;
    }
    vector<vector<int>> days(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> days[i][j];
        }
    }
    vector<int> dp(m+1);
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i < m + 1; i++) {
        dp[i] = days[dp[i - 1]-1][dp[i - 2]-1];
    }
    cout << dp[m];
}