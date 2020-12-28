#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<vector>
using namespace std;
 struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
 void pushres(stack<TreeNode*> &s, TreeNode* t) {
     if (t != NULL) {
         s.push(t);
     }
 }

 
 class Solution {
 public:
     vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<vector<int>> m;
         stack<TreeNode*> s1;
         stack<TreeNode*> s2;
         s1.push(root);
         while (!s1.empty() || !s2.empty()) {
             vector<int> m1;
             while (!s1.empty()) {
                 pushres(s2,s1.top()->left);
                 pushres(s2,s1.top()->right);
                 m1.push_back(s1.top()->val);
                 s1.pop();
             }
             vector<int> m2;
             while (!s2.empty()) {
                 pushres(s1, s2.top()->right);
                 pushres(s1, s2.top()->left);
                 m2.push_back(s2.top()->val);
                 s2.pop();
             }
             if (!m1.empty())
                 m.push_back(m1);
             if (!m2.empty())
                 m.push_back(m2);
         } 
         return m;
    }
    
};
 int main() {
     TreeNode* n = new TreeNode(1);
     Solution s ;
     s.zigzagLevelOrder(n);
 }

 
