/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> lst;
        if(!root) return lst;
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        TreeNode* tmp;
        
        vector<int> tmplst;
        while(!que.empty()){
            tmp  = que.front();
            que.pop();
            
            if(tmp) tmplst.emplace_back(tmp->val);
            
            if(tmp==NULL){
                if(!que.empty()){
                    que.push(NULL);
                }
                lst.emplace_back(tmplst);
                tmplst.clear();
            }else{
                if(tmp->left){
                    que.push(tmp->left);
                }
                
                if(tmp->right){
                    que.push(tmp->right);
                }
            }
        }
        return lst;
    }
};
