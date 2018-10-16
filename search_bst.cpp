#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

///for bst: left < root & right>root///

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* searchBST(TreeNode* root, int val) {
		///emty or at end
		if (root == NULL || root->val == val )
			return root;
		
		else {
			if (root->left == NULL && root->right == NULL)
				return NULL;
		
			else if(val < root->val){
				TreeNode* n = searchBST(root->left, val);
				return n;
			}
			else {
				TreeNode* n = searchBST(root->right, val);
				return n;
			}
		}
	}
};