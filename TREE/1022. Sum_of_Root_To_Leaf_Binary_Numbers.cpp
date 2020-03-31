/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:

Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22

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
    int sum=0;
    
Approach : 1

    void dfs(TreeNode* root, int tmp){
        if(!root) return;
        tmp*=2;
        tmp+=root->val;
        if(!root->left && !root->right) sum+=tmp;
        
        dfs(root->left,tmp);
        dfs(root->right,tmp);
    }
    
Approach : 2 ( Slower )

    void dfs(TreeNode* root ,string tmp ,  int i){
        if(!root) return;
        
        dfs(root->left, tmp + to_string(root->val) ,i+1);
        if(!root->right && !root->left){
            tmp+=to_string(root->val);
            int res=0;
            for(int i=0; i < tmp.length(); i++){
                if(tmp[i]=='1'){
                    res+=(pow(2,tmp.length()-i-1));
                }
            }
            sum+=res;
        }
        dfs(root->right, tmp + to_string(root->val) ,  i+1);
    }

    int sumRootToLeaf(TreeNode* root) {
        dfs(root,0);
	  //dfs(root,"",0);  for second approach
        return sum;   
    }
};
