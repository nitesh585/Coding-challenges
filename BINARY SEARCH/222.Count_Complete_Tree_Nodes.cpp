/*
Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6


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
    
    int  leftNodes(TreeNode* root){
       return root==NULL ? 0 : 1 + leftNodes(root->left);
    }
    
    
    int  rightNodes(TreeNode* root){
       return root==NULL ? 0 : 1 + rightNodes(root->right);
    }
    
    int countNodes(TreeNode* root) {
        int left = leftNodes(root);
        int right = rightNodes(root);
        
        return left==right ? pow(2,left) - 1 : 1+ countNodes(root->left) + countNodes(root->right) ;
        
    }
};
