/*
Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than or equal to the node's key.
    The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
    Both the left and right subtrees must also be binary search trees.

For example:
Given BST [1,null,2,2],

   1
    \
     2
    /
   2

 

return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).

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
    vector<int> mods;
    
    // Find maximum frequency
    void maxFreq(TreeNode* root , int &ans, int& tmp, int& parent){
        if(!root) return;
        
        maxFreq(root->left, ans, tmp, parent);
                
        if(parent==root->val) tmp++;
        else tmp=1;
        
        ans = max(ans,tmp);
        
        parent = root->val;
        maxFreq(root->right, ans, tmp, parent);
    }
    
    // if frequency of any element is equal to max frequency then it would be added to mods list.
    void modes(TreeNode* root ,int&ans , int& tmp, int& parent, int mx){
        if(!root) return;
        
        modes(root->left, ans, tmp, parent, mx);
        
        if(parent==root->val) tmp++;
        else tmp=1;
        
        if(tmp==mx) mods.emplace_back(root->val);
        
        parent = root->val;    
        modes(root->right, ans, tmp, parent, mx);
    }
    
    
    vector<int> findMode(TreeNode* root) {
        
        int ans=INT_MIN, parent=-1, tmp=1;    
        maxFreq(root, ans, tmp, parent);
    
        parent=-1;  tmp=1;
        int res=INT_MIN;
        
        modes(root, res, tmp, parent, ans);
        return mods;
    }
};
