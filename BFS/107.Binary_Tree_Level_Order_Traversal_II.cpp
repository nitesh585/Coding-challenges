/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its bottom-up level order traversal as:

[
  [15,7],
  [9,20],
  [3]
]

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        TreeNode* tmp;
        vector<int> tmplst;
        
        while(!que.empty()){
            tmp = que.front();
            que.pop();
            
            if(tmp) tmplst.emplace_back(tmp->val);
            
            if(tmp==NULL){
                if(!que.empty()){
                    que.push(NULL);
                }
                res.emplace_back(tmplst);
                tmplst.clear();
            }else{
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right); 
            }
        }
        reverse(res.begin() , res.end());
        return res;
    }
};
