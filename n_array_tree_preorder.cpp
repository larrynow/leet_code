#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>

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
	vector<int> preorder(Node* root) {
		vector<int> ans_vec;
		stack<Node*> s;
		if (root == NULL) {
			return ans_vec;
		}
		s.push(root);
		while (s.size() != 0) {
			Node* node = s.top();
			s.pop();
			ans_vec.push_back(node->val);
			for (int i = node->children.size() - 1; i >= 0;i--){
				s.push(node->children[i]);

			}
		}

		return ans_vec;		
	}

};