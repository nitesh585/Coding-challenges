/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]

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
    int pindex;
        
    TreeNode* build(vector<int>& inorder,  vector<int>& postorder,int strt, int end){
        if(strt>end) return NULL;
        
        
        TreeNode* node = new TreeNode(postorder[pindex--]);
        
        if(strt==end) return node;
        
        int index = search(inorder, strt, end, node->val);
        
        node->right = build(inorder, postorder,index+1,end);      
        node->left  = build(inorder, postorder,strt,index-1); 
        
        return node;
        
    }
    
    int search(vector<int>& inorder, int strt, int end, int val){
        for(; strt<=end; strt++){
            if(inorder[strt]==val){
                return strt;
            }
        }
        return strt;
    }
    
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        pindex = inorder.size()-1;
        return build(inorder, postorder,0,inorder.size()-1);
    }
};
