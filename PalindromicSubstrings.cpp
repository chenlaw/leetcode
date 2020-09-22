  #include<vector>
  #include<string>
  #include<stack>
  #include<iostream>
  #include<unordered_map>
  using namespace std;
int countSubstrings(string s) {
    int l = s.length();
    if(l==2){
        if(s.at(0)==s.at(1))
        return 3;
    }else if (l<2){
        return l;
    }
    vector<vector<bool>> dp(l,vector<bool>(l,false));
    for(int i=0;i<l;i++){
        dp[i][i]=true;
    }
     for(int i=0;i<l-1;i++){
         if(s.at(i)==s.at(i+1))
            dp[i][i+1]=true;
    }
    
    for(int i=1;i<l-1;i++){
        for(int j=1;i-j>=0&&i+j<l;j++){
            dp[i-j][i+j] =s.at(i-j)==s.at(i+j)&& dp[i-j+1][i+j-1];
        }
    }
    for(int i=1;i<l-2;i++){
        if(!dp[i][i+1])
            continue;
        for(int j=1;i-j>=0&& i+j+1<l;j++){
            if(s.at(i-j)==s.at(i+j)&& dp[i-j+1][i+j])
                dp[i-j][i+j+1]=true;
        else
            break;
    }}
    int res=0;
    for(int i=0;i<l;i++){
        for(int j=i;j<l;j++){
            if(dp[i][j])
            res+=1;
        }
    }
    return res;
}

int main(){
    string s ="sssss";
    int res =countSubstrings(s);
    cout<<res;
}