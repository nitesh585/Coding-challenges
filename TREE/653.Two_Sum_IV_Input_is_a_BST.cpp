/*
Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True

 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False
*/


// Time - O(nlogn) space-O(1) (if don't include the stack used in recursion)
class Solution {
public:
    
    TreeNode* main;
    bool ans=false;
    
    TreeNode* binarysearch(TreeNode* root, int val){
        if(!root) return NULL;
        
        if(root->val==val) return root; 
        
        return root->val < val ? binarysearch(root->right, val) :binarysearch(root->left, val);
    }
    
    void find(TreeNode* root,int k){
        if(!root) return;
        
        if(!ans && binarysearch(main,k-root->val) && binarysearch(main,k-root->val)!=root ) {
            ans=true;
            return;
        }
        
        find(root->left,k);
        find(root->right,k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        main = root;
        find(root,k);
        return ans;
    }
};


other approaches ( time-O(n)  space-O(n) )
- use Hashset
- use BFS and Hashset
- use list to store the values

