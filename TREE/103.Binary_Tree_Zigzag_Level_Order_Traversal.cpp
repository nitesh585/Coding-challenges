/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(!root) return ans;
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        TreeNode* tmp;
        
        vector<int> tmplst;
        bool flag = true;
        while(!que.empty()){
            tmp = que.front();
            que.pop();
            
            if(tmp) tmplst.emplace_back(tmp->val);
            
            if(tmp==NULL){
                if(!que.empty()){
                    que.push(NULL);
                }
                
                if(flag){
                    flag = false;
                }else{
                    flag = true;
                    reverse(tmplst.begin() ,tmplst.end());
                }
                ans.emplace_back(tmplst);
                tmplst.clear();
                
            }else{
                
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
                
            }    
        }
        
        return ans;
    }
};
