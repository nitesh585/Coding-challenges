/*
Given a binary tree, return the preorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,2,3]

Follow up: Recursive solution is trivial, could you do it iteratively?

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
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> lst;
        if(!root) return lst;
        
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            lst.push_back(stk.top()->val);
            
            TreeNode* tmp = stk.top();
            stk.pop();
            
            if(tmp->right) stk.push(tmp->right);
            if(tmp->left) stk.push(tmp->left);
            
        }
        return lst;
    }
};
