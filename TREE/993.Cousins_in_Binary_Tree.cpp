/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

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
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        
        vector<int> lst;
        
        TreeNode* tmp;
        while(!que.empty()){
            tmp = que.front();
            
            if(tmp){ 
                lst.emplace_back(tmp->val);
            
            if(tmp->right && (tmp->right->val==x)){
                if(tmp->left && (tmp->left->val==y)) return false;
            }
            if(tmp->left && (tmp->left->val==x)){
                if(tmp->right && (tmp->right->val==y)) return false;
            }
            }
            que.pop();
            
            if(tmp==NULL){
                if(!que.empty()) que.push(NULL);
                
                if(find(lst.begin(),lst.end(),x)!=lst.end() && (find(lst.begin(),lst.end(),y)!=lst.end() ) ) 
                    return true;
                   
                   
                   lst.clear();
            }else{
                if(tmp->left) que.push(tmp->left);
                if(tmp->right) que.push(tmp->right);
            }
        }
        return false;
    }
};
