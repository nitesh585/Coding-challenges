/*
Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
    \
     3
    /
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).

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
    
    void dfs(TreeNode* root, int& pr, int& ans){
        if(!root) return ;
        
        dfs(root->left , pr, ans);
            if(pr!=-1){
                ans = min(ans, abs(root->val-pr));
            }
        
        pr = root->val;
        dfs(root->right , pr, ans);
    }
    
    int getMinimumDifference(TreeNode* root) {
        int pr=-1;
        int ans = INT_MAX;
        dfs(root , pr, ans);
        return ans;
    }
};	
