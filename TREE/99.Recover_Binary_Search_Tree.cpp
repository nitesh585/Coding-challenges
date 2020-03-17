/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Example 1:

Input: [1,3,null,null,2]

   1
  /
 3
  \
   2

Output: [3,1,null,null,2]

   3
  /
 1
  \
   2

Example 2:

Input: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

Output: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3

Follow up:

    A solution using O(n) space is pretty straight forward.
    Could you devise a constant space solution?
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
    
    // inorder traversal to find the elements to be swapped
    void inorder(TreeNode* root, int &a, int &b ,bool &flag){
        if(!root) return;
        inorder(root->left ,a,b,flag);
        
        if(flag){
            if(a<=root->val){
                a=root->val;
            }else{
                b = root->val;
                flag = false;
            }
        }else{
            if(a>root->val){
                b = root->val;
            }
        }
        inorder(root->right,a,b,flag);
    }
    
    // search and swap the elements
    void searchAndSwap(TreeNode* root, int a, int b){
        if(!root) return;
        searchAndSwap(root->left,a,b);
        
        if(root->val == a) root->val = b; 
        else if(root->val == b) root->val = a;
        
        searchAndSwap(root->right,a,b);
    }
    
    void recoverTree(TreeNode* root) {
        int a=INT_MIN,b = 0;
        bool flag=true;
        inorder(root,a,b,flag);
        searchAndSwap(root,a,b);
    }
};
