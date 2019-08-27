/*
 * @lc app=leetcode id=662 lang=cpp
 *
 * [662] Maximum Width of Binary Tree
 *
 * https://leetcode.com/problems/maximum-width-of-binary-tree/description/
 *
 * algorithms
 * Medium (39.48%)
 * Likes:    720
 * Dislikes: 142
 * Total Accepted:    37.8K
 * Total Submissions: 95.7K
 * Testcase Example:  '[1,3,2,5,3,null,9]'
 *
 * Given a binary tree, write a function to get the maximum width of the given
 * tree. The width of a tree is the maximum width among all levels. The binary
 * tree has the same structure as a full binary tree, but some nodes are null.
 * 
 * The width of one level is defined as the length between the end-nodes (the
 * leftmost and right most non-null nodes in the level, where the null nodes
 * between the end-nodes are also counted into the length calculation.
 * 
 * Example 1:
 * 
 * 
 * Input: 
 * 
 * ⁠          1
 * ⁠        /   \
 * ⁠       3     2
 * ⁠      / \     \  
 * ⁠     5   3     9 
 * 
 * Output: 4
 * Explanation: The maximum width existing in the third level with the length 4
 * (5,3,null,9).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        /  
 * ⁠       3    
 * ⁠      / \       
 * ⁠     5   3     
 * 
 * Output: 2
 * Explanation: The maximum width existing in the third level with the length 2
 * (5,3).
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2 
 * ⁠      /        
 * ⁠     5      
 * 
 * Output: 2
 * Explanation: The maximum width existing in the second level with the length
 * 2 (3,2).
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: 
 * 
 * ⁠         1
 * ⁠        / \
 * ⁠       3   2
 * ⁠      /     \  
 * ⁠     5       9 
 * ⁠    /         \
 * ⁠   6           7
 * Output: 8
 * Explanation:The maximum width existing in the fourth level with the length 8
 * (6,null,null,null,null,null,null,7).
 * 
 * 
 * 
 * 
 * Note: Answer will in the range of 32-bit signed integer.
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
    int widthOfBinaryTree(TreeNode* root) {
        int depth = get_depth(root);
        vector<vector<unsigned int>> edges = vector<vector<unsigned int>>(depth, vector<unsigned int>(2, -1));
        get_edge(root, 0, 0, edges);
        int ans = 0;
        for(auto e:edges)
        {
            int width = (e[1]-e[0] + 1);
            //cout<<width<<endl;
            if(width>ans)
                ans = width;
        }

        return ans;
    }

    int get_depth(TreeNode* root)
    {
        if(root==NULL) return 0;
        return max(get_depth(root->left), get_depth(root->right))+1;
    }

    void get_edge(TreeNode* root, int layer, unsigned int pos, vector<vector<unsigned int>>& edges)
    {
        if(root==NULL) return;
        if(edges[layer][0]==-1||pos < edges[layer][0])
            edges[layer][0] = pos;
        if(edges[layer][1]==-1||pos > edges[layer][1])
            edges[layer][1] = pos;
        if(root->left)
            get_edge(root->left, layer+1, pos*2, edges);
        if(root->right)
            get_edge(root->right, layer+1, pos*2 + 1, edges);
    }
};


