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
		
		if (root == NULL)
			return NULL;
		if (root == p || root == q)
			return root;

		auto le = lowestCommonAncestor(root->left, p, q);
		auto ri = lowestCommonAncestor(root->right, p, q);
		if (le != NULL && ri != NULL)
			return root;
		if (le != NULL)
			return le;
		if (ri != NULL)
			return ri;
		
		return NULL;
	}
};