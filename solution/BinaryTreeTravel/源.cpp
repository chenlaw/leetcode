#include<vector>
#include<stack>
using namespace std;

  //Definition for a binary tree node.
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
  vector<int> preorderTraversal(TreeNode* root) {
      vector<int> res;
      if (root == nullptr)
          return res;
      stack<TreeNode*> s;
      s.push(root);
      while (!s.empty()) {
          TreeNode* tmp = s.top();
          s.pop();
          res.push_back(tmp->val);
          if (tmp->right != nullptr)s.push(tmp->right);
          if (tmp->left != nullptr)s.push(tmp->left);
      }
      return res;
  }
  vector<int> inorderTraversal(TreeNode* root) {
      vector<int> res;
      if (root == nullptr)
          return res;
      stack<TreeNode*> s;
      s.push(root);
      while (s.top()->left != nullptr)
          s.push(s.top()->left);
      while (!s.empty()) {
          TreeNode* tmp = s.top();
          s.pop();
          res.push_back(tmp->val);
          if (tmp->right != nullptr) {
              s.push(tmp->right);
              while (s.top()->left != nullptr)
                  s.push(s.top()->left);
          }
      }
      return res;
  }
  vector<int> postorderTraversal(TreeNode* root) {
      vector<int> res;
      if (root == nullptr)
          return res;
      stack<TreeNode*> s;
     
      TreeNode* tmp = root;
      TreeNode* prev = nullptr;
      while (tmp!=nullptr||!s.empty()) {
          while (tmp != nullptr) {
                s.push(tmp);
                tmp = tmp->left;
          }
          tmp = s.top();
          s.pop();          
          if (tmp->right == nullptr || tmp->right == prev) {
              res.push_back(tmp->val);
              prev = tmp;
              tmp = nullptr;
          }
          else {
              s.push(tmp);
              tmp= tmp->right;
          }
      }
      return res;
  }

  int main() {
      TreeNode* T3 = new TreeNode(3);
      TreeNode* T2 = new TreeNode(2, T3,nullptr);
      TreeNode* T1 = new TreeNode(1, nullptr,T2);
      vector<int> v=postorderTraversal(T1);
  }
  