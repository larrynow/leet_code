#include<iostream>
#include<set>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * constructMaximumBinaryTree(vector<int>& nums) {
		//use max_element to get the max one's position
		auto max = max_element(nums.begin(),nums.end());
		//cout << *max<<endl;
		TreeNode* tree_root = new TreeNode(*max);//TreeNode tree_root(*max);

		vector<int> half_first(nums.begin(), max);
		vector<int> half_second(max+1,nums.end());

		if (half_first.size() != 0) {
			tree_root->left = constructMaximumBinaryTree(half_first);
		}
		if (half_second.size() != 0) {
			tree_root->right = constructMaximumBinaryTree(half_second);
		}


		return tree_root;
	}


};

int main() {
	Solution sol = Solution();
	vector<int> nums = { 3,2,1,6,0,5 };
	//vector<int> nums = { 3,2};

	cout<<sol.constructMaximumBinaryTree(nums)->left->right->right->val<<endl;
	system("pause");
	return 0;
}