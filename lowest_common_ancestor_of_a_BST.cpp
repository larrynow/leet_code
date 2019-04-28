#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

		while (root) {
			if (root->val <= max(q->val, p->val) && root->val >= min(q->val, p->val))
				return root;
			else if (root->val < min(q->val, p->val))
				root = root->right;
			else
				root = root->left;
		}
		
		return NULL;
	}
};