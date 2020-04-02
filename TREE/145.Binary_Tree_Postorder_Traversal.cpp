/*
Given a binary tree, return the postorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [3,2,1]

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        
        stack<TreeNode*> stk;
        stk.push(root);
        
        TreeNode* tmp;
        
        while(!stk.empty()){
            tmp = stk.top();
            stk.pop();
            
            if(tmp) ans.insert(ans.begin(),tmp->val);
           
            if(tmp->left) stk.push(tmp->left);
            if(tmp->right) stk.push(tmp->right);
            
        }
        
        return ans;
    }
};
