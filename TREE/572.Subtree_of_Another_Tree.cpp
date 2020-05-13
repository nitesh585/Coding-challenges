/*
Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2

Given tree t:

   4 
  / \
 1   2

Return true, because t has the same structure and node values with a subtree of s.

 

Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0

Given tree t:

   4
  / \
 1   2

Return false.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    bool matchTree(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(!a || !b) return false; 
        return a->val==b->val && matchTree(a->left,b->left) && matchTree(a->right,b->right);
    }
    
    bool dfs(TreeNode* s, TreeNode* t){
        return s!=NULL && (matchTree(s,t) || dfs(s->left,t) || dfs(s->right,t));  
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return dfs(s,t);
    }
};
