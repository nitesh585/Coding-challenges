/*
Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.

Return the smallest level X such that the sum of all the values of nodes at level X is maximal.

 

Example 1:

Input: [1,7,0,7,-8,null,null]
Output: 2
Explanation: 
Level 1 sum = 1.
Level 2 sum = 7 + 0 = 7.
Level 3 sum = 7 + -8 = -1.
So we return the level with the maximum sum which is level 2.

 

Note:

    The number of nodes in the given tree is between 1 and 10^4.
    -10^5 <= node.val <= 10^5



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
    int maxLevelSum(TreeNode* root) {
        int mxLevel=1, tmpLevel=1;
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        int mxSum = root->val;
        
        int tmpSum=0;
        while(!que.empty()){
            TreeNode* curr = que.front();
            que.pop();
            
            if(curr==NULL){
                 
                if(!que.empty()){
                    que.push(NULL);
                }
                if(mxSum<tmpSum){
                    mxSum = tmpSum;
                    mxLevel = tmpLevel;
                }
                tmpSum=0;
                tmpLevel++;
                
            }else{
                
                if(curr->left){
                    que.push(curr->left);
                }
                
                if(curr->right){
                    que.push(curr->right);
                }
                
                tmpSum += curr->val;
            }
            
        }
        return mxLevel;
    }
};
