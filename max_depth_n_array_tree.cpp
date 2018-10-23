#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

// Definition for a Node.
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
	int maxDepth(Node* root) {
		if (root == NULL) {
			return 0;
		}
		int flag = 0;
		for (auto child:root->children ) {
			//this makes time limit exceed;
			//if (maxDepth(root->children[i]) > max)
			//    max = maxDepth(root->children[i]);
			flag = max(maxDepth(child), flag);
		}

		return flag + 1;
	}
};