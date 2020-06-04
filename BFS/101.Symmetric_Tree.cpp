Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3




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
    
    bool isSymmetric(TreeNode* root) {
        return symmetry(root,root);
    }
    
    bool symmetry(TreeNode* r1,TreeNode* r2){
        if(!r1 && !r2){
            return true;
        }
        if(!r2 || !r1){
            return false;
        }
        
        return  (r1->val==r2->val) && symmetry(r1->left,r2->right) && symmetry(r1->right,r2->left);
        
    }
    
};
