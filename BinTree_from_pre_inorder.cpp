#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<unordered_map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0) return NULL;
		vector<TreeNode*> s;
		unordered_map<int, int> map;
		for (int i = 0; i < inorder.size(); i++) map[inorder[i]] = i;//construct map of postion and values in inorder seq;
		TreeNode* root = new TreeNode(preorder[0]);
		s.push_back(root);

		for (int i = 1; i < preorder.size(); i++) {
			TreeNode* node = new TreeNode(preorder[i]);
			if (map[preorder[i]] < map[s.back()->val]) {
				s.back()->left = node;//if the next val in preorder locates on the left of the current val in inorder seq;
				s.push_back(s.back()->left);
			}
			else {
				TreeNode* parent;
				while (!s.empty() && (map[preorder[i]] > map[s.back()->val])) {//if > means in the right sub tree, then the left part is done, so pop;
					parent = s.back();//current val is stack top's right child or the top's ancenster's ;
					s.pop_back();//pop until the top one in the right of current one in inorder, and thus the current's parent is the last one;  
				}
				parent->right = node;
				s.push_back(node);
			}
		}

		return root;

	}
};