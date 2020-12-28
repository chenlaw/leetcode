#include<vector>
#include<iostream>
#include<string>
using namespace std;
bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.length();
    int l2 = s2.length();
    int l3 = s3.length();
    if ((l1 + l2 )!= l3) {
        return false;
    }
    if (l1 == 0 || l2 == 0) {
        return s3 == (l2 == 0 ? s1 : s2);
    }
    vector<vector<bool>> dp(l1+1, vector<bool>(l2+1));
    dp[0][0] = true;
    for (int j = 1; j < l2 + 1; j++) {
        dp[0][j] = dp[0][j-1]& (s2.at(j-1) == s3.at(j-1));
       
    }
    for (int j = 1; j < l1 + 1; j++) {
        dp[j][0] =dp[j-1][0]&( s1.at(j - 1) == s3.at(j - 1));
    }

    for (int i = 1; i < l1 + 1; i++) {
        for (int j = 1; j < l2 + 1; j++) {
            dp[i][j] = (dp[i - 1][j] & (s1.at(i - 1) == s3.at(i + j - 1)) | (dp[i][j - 1] & (s2.at(j - 1) == s3.at(i + j - 1))));
        }
    }

}
int main(){
    string s1 = "db";
    string s2 = "b";
    string s3 = "cbb";
    bool res = isInterleave(s1, s2, s3);
    cout << res;
}