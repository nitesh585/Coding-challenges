/*
Given a binary tree, return the sum of values of its deepest leaves.

Example 1:

Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15

 

Constraints:

    The number of nodes in the tree is between 1 and 10^4.
    The value of nodes is between 1 and 100.

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
    
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        
        return max(maxDepth(root->left) , maxDepth(root->right))+1;
    }
    
    void helper(TreeNode* root, int &ans,int depth,int tmp){
        if(!root) return ;
        tmp++;
        if(!root->left &&  !root->right  && tmp==depth){
            ans+=root->val;
        }
        
        helper(root->left,ans,depth,tmp);
        helper(root->right,ans,depth,tmp);
        
        tmp--;
    }
    
    
    int deepestLeavesSum(TreeNode* root) {
        int ans=0,tmp =0;
        int depth = maxDepth(root);
        
        helper(root,ans,depth,tmp);
        
        return ans;
    }
};
