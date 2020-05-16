/*

Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5

You can return this binary search tree:

         4
       /   \
      2     7
     / \   /
    1   3 5

This tree is also valid:

         5
       /   \
      2     7
     / \   
    1   3
         \
          4

Constraints:

    The number of nodes in the given tree will be between 0 and 10^4.
    Each node will have a unique integer value from 0 to -10^8, inclusive.
    -10^8 <= val <= 10^8
    It's guaranteed that val does not exist in the original BST.

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
    
    void insert(TreeNode* root, TreeNode* parent, int val) {
        if(!root){
            if(!parent->left && parent->val >= val ){
                parent->left = new TreeNode(val);
            }else{
                parent->right = new TreeNode(val);
            }
            return ;
        }
        
        if(root->val>=val){
            insert(root->left, root, val);
        }else{
            insert(root->right, root, val);
        }   
    }
    
    
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            root = new TreeNode(val);
            return root;
        }
        insert(root,root,val);
        return root;
    }
};
