#include<stack>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<queue>
using namespace std;

 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
int getMinimumDifference(TreeNode* root) {
    if (root == NULL)return 0;
    stack<TreeNode*> s;
    s.push(root);
    int ans = INT_MAX;
    int tmp = INT_MAX;
    while (s.top()->left != NULL) {
        s.push(s.top()->left);
    }
    while (!s.empty()) {
        TreeNode* n = s.top();
        s.pop();
        if (ans > abs(tmp - n->val))
            ans = abs(tmp - n->val);
        tmp = n->val;
        if (n->right != NULL) {
            s.push(n->right);
            while (s.top()->left != NULL) {
                s.push(s.top()->left);
            }
        }
    }
    return ans;
}
vector<int> findMode(TreeNode* root) {
    vector<int> res;
    if (root == NULL)return {};
    stack<TreeNode*> s;
    s.push(root);
    int ans_count = 0;
    int tmp = INT_MIN; int tmp_count = 0;
    while (s.top()->left != NULL) {
        s.push(s.top()->left);
    }
    while (!s.empty()) {
        TreeNode* n = s.top();
        s.pop();
        if (n->val == tmp)
            tmp_count += 1;
        else {
            if (tmp_count > ans_count) {
                ans_count = tmp_count;
                res.clear();
                res.push_back(tmp);
            }
            else if (tmp_count == ans_count)
                res.push_back(tmp);
            tmp = n->val;
            tmp_count = 1;
        }
        if (n->right != NULL) {
            s.push(n->right);
            while (s.top()->left != NULL) {
                s.push(s.top()->left);
            }
        }
    }
    if (tmp_count > ans_count) {
        ans_count = tmp_count;
        res.clear();
        res.push_back(tmp);
    }
    else if (tmp_count == ans_count)
        res.push_back(tmp);
    return res;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == NULL) return root;
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> parents;
    queue<TreeNode* > qu;
    qu.push(root);
    while (!qu.empty()) {
        TreeNode* t = qu.front();
        qu.pop();
        if (t->left != NULL) {
            qu.push(t->left);
            parent.emplace(t->left, t);
        }
        if (t->right != NULL) {
            qu.push(t->right);
            parent.emplace(t->right, t);
        }
    }
    TreeNode* tmp = p;
    while (tmp != root) {
        parents.emplace(tmp);
        tmp = parent[tmp];
    }
    parents.emplace(root);
    tmp = q;
    while (parents.find(tmp) == parents.end()) {
        tmp = parent[tmp];
    }
    return tmp;
}
int main() {
    TreeNode* t = new TreeNode(1);
    t->right = new TreeNode(2);
    t->left = new TreeNode(2);
    auto r = lowestCommonAncestor(t,t->right,t->left);
}