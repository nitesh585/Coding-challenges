/*
Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 
Example 1:

Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:

Input: root = [1,2,3]
Output: [1,3]

Example 3:

Input: root = [1]
Output: [1]

Example 4:

Input: root = [1,null,2]
Output: [1,2]

Example 5:

Input: root = []
Output: []


Constraints:

    The number of the nodes in the tree will be in the range [1, 104].
    -231 <= Node.val <= 231 - 1

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
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int size = que.size();
            int mx = INT_MIN;
            
            while(size--){
                TreeNode* tmp = que.front();
                que.pop();
                
                mx = max(mx, tmp->val);
                
                if(tmp->left){
                    que.push(tmp->left);
                }
                
                if(tmp->right){
                    que.push(tmp->right);
                }
            }
            ans.emplace_back(mx);
        }
        
        return ans;
    }
};
