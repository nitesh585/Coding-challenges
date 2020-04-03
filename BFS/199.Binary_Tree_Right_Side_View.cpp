/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        
        TreeNode* tmp;
        TreeNode* tmp2;
        
        while(!que.empty()){
            tmp = que.front();
            que.pop();
            tmp2 = que.front();
            if(!tmp2) res.emplace_back(tmp->val);
            
            if(!tmp){
                if(!que.empty()) que.push(NULL);
            }else{
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
            }   
        }
        
        return res;
    }
};
