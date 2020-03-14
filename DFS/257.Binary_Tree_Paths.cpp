/*
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3

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
    
    void dfs(TreeNode* root, vector<string> &ans, string tmp){
        if(!root) return;
        
        if(root->left==NULL && root->right==NULL){
            tmp+= to_string(root->val);
            ans.push_back(tmp);
        }
        
        tmp += to_string(root->val)+"->";
        dfs(root->left,ans,tmp);
        dfs(root->right,ans,tmp);
        
        return;
    }
    
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string tmp;
        dfs(root, ans,tmp);
        return ans;
    }
};
