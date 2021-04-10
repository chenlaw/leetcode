#include<iomanip>
#include<string>
#include<vector>
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
#include<unordered_map>
#include<iomanip>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int val) {
		this->val = val;
		this->left = nullptr;
		this->right = nullptr;
	}
};
TreeNode* buildTree(string& s, int begin, int end) {
	if (begin >= end)return nullptr;
	int rootval = 0;
	for (begin; begin <= end; begin++) {
		if (s.at(begin) >= '0' && s.at(begin) <= '9')
			rootval = rootval * 10 + s.at(begin) - '0';
		else
			break;
	}
	TreeNode* root = new TreeNode(rootval);
	begin++;end--;//È¥µôÀ¨ºÅ
	int left = 0;
	int middle = begin;
	for (middle; middle <= end; middle++) {
		if (s.at(middle) == '(')
			left++;
		else if (s.at(middle) == ')')
			left--;
		else if (s.at(middle) == ',') {
			if (left == 0)
				break;
		}
	}
	root->left = buildTree(s,begin, middle - 1);
	root->right = buildTree(s, middle + 1, end);
	return root;

}
void inOrder(TreeNode* root, vector<int>& res) {
	if (root == nullptr)return;
	inOrder(root->left,res);
	res.push_back(root->val);
	inOrder(root->right, res);
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		string s;
		cin >> s;
		TreeNode* root = buildTree(s, 0, s.length() - 1);
		vector<int> res;
		inOrder(root, res);
		int l = res.size();
		for (int i = 0; i < l - 1; i++) {
			cout << res[i] << " ";
		}
		cout << res[l - 1] << endl;
	}
}