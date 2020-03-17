/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \      \
7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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
    
    void dfs(TreeNode* root, int sum, bool &result){
        
        if(!root) return;
        
        if( (root->left==NULL && root->right==NULL) && sum==root->val){
            result = true;
            return;
        }
    
        dfs(root->left, sum-root->val, result);
        dfs(root->right, sum-root->val, result);
        
    }
    
    bool hasPathSum(TreeNode* root, int sum) {
        bool result = false;
        dfs(root,sum,result);
        return result;
    }
};
