/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

    a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7

Return true.
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
    
    int inorder(TreeNode* root){
        if(!root) return 0;
        
        int hleft = inorder(root->left);
        int hright = inorder(root->right);
        
        if(hleft==-1 || hright==-1 || abs(hleft-hright)>1) return -1;
        
        
        return max(hleft,hright)+1;
    }
    
    bool isBalanced(TreeNode* root) {
        return inorder(root)!=-1;
    }
};
