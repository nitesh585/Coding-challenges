/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]

Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7
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
    
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int strt, int end,int &pindex){
        if(strt > end) return NULL;
        
        TreeNode* node = new TreeNode(preorder[pindex++]);
        if(strt==end) return node;
        
        int index = search(inorder, node->val ,strt, end);
        
        node->left = build(preorder, inorder, strt, index-1,pindex);
        node->right = build(preorder, inorder,index+1, end ,pindex);
        
        return node;
    }
    
    
    int search(vector<int>& inorder,int val,int strt, int end){
        for(; strt<=end ; ++strt)
            if(inorder[strt]==val) return strt;
        return -1;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pindex = 0;
        return  build(preorder, inorder, 0, inorder.size()-1,pindex);
     
    }
};
