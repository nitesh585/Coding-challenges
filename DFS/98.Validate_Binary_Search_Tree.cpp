/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true

Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
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
    
    void inorder(TreeNode* root , vector<int> &list){
        if(!root) return ;
        
        inorder(root->left,list);
        list.push_back(root->val);
        inorder(root->right ,list);
    }
    
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        
        vector<int> list;
        inorder(root,list);
        
        for(int i=0; i<list.size()-1;i++)
            if( list[i] >= list[i+1]) return false;
        
        return true;
    }
};
