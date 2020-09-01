/*
Given two binary search trees root1 and root2.

Return a list containing all the integers from both trees sorted in ascending order.

 

Example 1:

Input: root1 = [2,1,4], root2 = [1,0,3]
Output: [0,1,1,2,3,4]

Example 2:

Input: root1 = [0,-10,10], root2 = [5,1,7,0,2]
Output: [-10,0,0,1,2,5,7,10]

Example 3:

Input: root1 = [], root2 = [5,1,7,0,2]
Output: [0,1,2,5,7]

Example 4:

Input: root1 = [0,-10,10], root2 = []
Output: [-10,0,10]

Example 5:

Input: root1 = [1,null,8], root2 = [8,1]
Output: [1,1,8,8]

 

Constraints:

    Each tree has at most 5000 nodes.
    Each node's value is between [-10^5, 10^5].


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
    
    void inorder(TreeNode* root, vector<int>& vec){
        if(root==NULL){
            return;
        }
        inorder(root->left, vec);
        vec.emplace_back(root->val);
        inorder(root->right, vec);
    }
    
    void merge(vector<int>& res, vector<int>& v1, vector<int>& v2){
        int n=0 , m=0;
        
        while(n<v1.size() && m<v2.size()){
            if(v1[n]< v2[m]){
                res.emplace_back(v1[n]);
                n++;
            }else{
                res.emplace_back(v2[m]);
                m++;
            }
        }
        
        while(n<v1.size()){
            res.emplace_back(v1[n]);
            n++;
        }
        
        while(m<v2.size()){
            res.emplace_back(v2[m]);
            m++;
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> res;
        
        if(!root1 && !root2){
            return res;
        }
        
        vector<int> v1, v2;
    
        inorder(root1,v1);
        inorder(root2,v2);
        
        merge(res, v1, v2);
        
        return res;
    }
};
