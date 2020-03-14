/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1

Return:

[
   [5,4,11,2],
   [5,8,4,5]
]

Pass by refrence method is faster than pass by value.

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
    
    void dfs(TreeNode* root, int sum,vector<int> &tmp, vector<vector<int>> &ans){
        if(!root) return;
        
        tmp.push_back(root->val);
    
        if(root->left==NULL && root->right==NULL){
            if(sum==root->val){
                ans.push_back(tmp);
            }
        }
        
        dfs(root->left,sum-root->val,tmp, ans);
        dfs(root->right, sum-root->val,tmp, ans);
        tmp.pop_back();
    }
    
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> tmp;
        dfs(root, sum, tmp, ans);
        return ans;
    }
};
