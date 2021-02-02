#include<vector>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
class TreeNode {
public:
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) {
    }
    TreeNode operator+( TreeNode* s) {

    }
    friend TreeNode operator+(TreeNode* f, int s) {

}
};

void InOrder(TreeNode* t, vector<TreeNode*>& trees) {
    if (t == NULL)
        return;
    InOrder(t->left, trees);
    trees.push_back(t);
    InOrder(t->right, trees);
}
TreeNode* KthNode(TreeNode* pRoot, int k)
{
    vector<TreeNode*> trees;
    InOrder(pRoot, trees);
    if (trees.size() == 0 || k > trees.size())
        return NULL;
    return trees[k - 1];
}
int main() {
    TreeNode* t = new TreeNode(4);
    t->left = new TreeNode(3);
    TreeNode *s=KthNode(t, 2);
    cout << s->val;
}