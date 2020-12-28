  #include<vector>
  #include<string>
  #include<stack>
  #include<iostream>
  #include<unordered_map>
  using namespace std;
bool isValid(string s) {
    int l =s.length();
    if(l==0)
        return true;
    if(l%2==1){
        return false;
    }
    stack<char> st;
    unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
    for(char c:s){
      if (pairs.count(c)) {
                if (st.empty() || st.top() != pairs[c]) {
                    return false;
                }
                st.pop();
            }
            else {
                st.push(c);
            }

    }
    return st.empty();
}
