/*
Consider all the leaves of a binary tree.  From left to right order, the values of those leaves form a leaf value sequence.

For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).

Two binary trees are considered leaf-similar if their leaf value sequence is the same.

Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.
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
    
    
    void leafSequence(TreeNode* root, vector<int> &vec){
        if(!root) return;
        
        if(root->left==NULL && root->right==NULL){
            vec.push_back(root->val);
            return;
        }
       
        
        leafSequence(root->left, vec);
        leafSequence(root->right, vec);
        
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> vec1, vec2;
        
        leafSequence(root1, vec1);
        leafSequence(root2, vec2);
        
        return vec1==vec2;
    }
};
