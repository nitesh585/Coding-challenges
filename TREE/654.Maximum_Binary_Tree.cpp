/*
 Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

    The root is the maximum number in the array.
    The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
    The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Example 1:

Input: [3,2,1,6,0,5]
Output: return the tree root node representing the following tree:

      6
    /   \
   3     5
    \    / 
     2  0   
       \
        1

Note:

    The size of the given array will be in the range [1,1000].

*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    pair<int,int> max(vector<int>& nums, int start, int end){
        int max=INT_MIN, idx=-1;
        for(int i=start; i<=end; i++){
            if(max<nums[i]){
                max = nums[i];
                idx = i;
            }
        }
        return {max,idx};
    }
    
    TreeNode* build(vector<int>& nums, int start, int end,TreeNode* root){
        if(start>end) return NULL;
        
        pair<int,int> p = max(nums,start, end);
        int max = p.first;
        int idx = p.second;
        
        root = new TreeNode(max);
        root->left = build(nums, start, idx-1, root);
        root->right = build(nums, idx+1, end, root);
        return root;
    }
    
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
          TreeNode* root;
          root = build(nums, 0, nums.size()-1, root);
          return root;
    }
};
