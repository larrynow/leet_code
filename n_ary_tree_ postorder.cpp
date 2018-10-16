#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
public:
	vector<int> postorder(Node* root) {
		vector<int> ans_vec;
		if (root == NULL) {
			return ans_vec;
		}
		for (int i = 0; i < root->children.size(); i++) {
			vector<int> vec = postorder(root->children[i]);
			///consider if the vector is empty
			if (vec.size() == 0)
				continue;
			ans_vec.insert(ans_vec.end(),vec.begin(), vec.end());			
		}
		ans_vec.push_back(root->val);

		return ans_vec;
	}
};