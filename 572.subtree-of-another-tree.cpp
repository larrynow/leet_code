/*
 * @lc app=leetcode id=572 lang=cpp
 *
 * [572] Subtree of Another Tree
 *
 * https://leetcode.com/problems/subtree-of-another-tree/description/
 *
 * algorithms
 * Easy (42.02%)
 * Likes:    1285
 * Dislikes: 49
 * Total Accepted:    110.9K
 * Total Submissions: 263.9K
 * Testcase Example:  '[3,4,5,1,2]\n[4,1,2]'
 *
 * 
 * Given two non-empty binary trees s and t, check whether tree t has exactly
 * the same structure and node values with a subtree of s. A subtree of s is a
 * tree consists of a node in s and all of this node's descendants. The tree s
 * could also be considered as a subtree of itself.
 * 
 * 
 * Example 1:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * 
 * Given tree t:
 * 
 * ⁠  4 
 * ⁠ / \
 * ⁠1   2
 * 
 * Return true, because t has the same structure and node values with a subtree
 * of s.
 * 
 * 
 * Example 2:
 * 
 * Given tree s:
 * 
 * ⁠    3
 * ⁠   / \
 * ⁠  4   5
 * ⁠ / \
 * ⁠1   2
 * ⁠   /
 * ⁠  0
 * 
 * Given tree t:
 * 
 * ⁠  4
 * ⁠ / \
 * ⁠1   2
 * 
 * Return false.
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // Recursively.
    /*
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s) return false;// Reach an end.
        if(isSame(s, t)) return true;

        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }

    bool isSame(TreeNode* s, TreeNode* t)
    {
        if(s==NULL && t==NULL) return true; 
        if(!t || !s ) return false;

        if(t->val != s->val) return false;

        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }*/

    // Compare with same depth nodes.
    vector<TreeNode*> nodes;
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s && !t) return true;
        if(!s || !t) return false;

        int depth_t = getDepth(t, -1);// For t just calculate depth.
        getDepth(s, depth_t);

        for(auto node : nodes)
        {
            if(isSame(node, t))
                return true;
        }

        return false;
    }

    int getDepth(TreeNode* tree, int d)
    {
        if(!tree)
        return 0;

        int tree_depth = max(getDepth(tree->left, d), getDepth(tree->right, d)) + 1;
        if(tree_depth == d)
            nodes.push_back(tree);
        
        return tree_depth;
    }

    bool isSame(TreeNode* s, TreeNode* t)// Compare tree nodes.
    {
        if(s==NULL && t==NULL) return true; 
        if(!t || !s ) return false;

        if(t->val != s->val) return false;

        return isSame(s->left, t->left) && isSame(s->right, t->right);
    }
};

