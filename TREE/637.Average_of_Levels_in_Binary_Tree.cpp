/*
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:

Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].

Note:

    The range of node's value is in the range of 32-bit signed integer.

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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> avg;
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);
        
        double sum=0, level_elements=-1;
        
        TreeNode* tmp;
        while(!que.empty()){
            tmp = que.front();
            que.pop();
            
            if(tmp) sum+=tmp->val;
            
            level_elements++;
            
            if(tmp==NULL){
                avg.emplace_back(sum/level_elements);
                sum=0;
                level_elements=-1;
                
                if(!que.empty()){
                    que.push(NULL);
                }
                
            }else{
                if(tmp->left) que.push(tmp->left);
                
                if(tmp->right) que.push(tmp->right);
            }
        }
        
        
        return avg;
    }
};
