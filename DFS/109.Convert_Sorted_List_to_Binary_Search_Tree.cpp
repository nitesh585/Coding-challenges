/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5

*/

//Time Complexity - O(N) and Space - O(N)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    
    TreeNode* buildTree(vector<int>& nums,int srt, int end){
        if(srt > end) return NULL;
        
        int mid = srt + (end-srt)/2;
        
        TreeNode* node = new TreeNode( nums[mid] );
        
        node->left = buildTree(nums,srt,mid-1);
        node->right = buildTree(nums,mid+1,end);
        
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        vector<int> nums;
        ListNode* tmp = head;
        while(tmp){
            nums.push_back(tmp->val);
            tmp = tmp->next;
        }
        
        return buildTree(nums,0,nums.size()-1);
    }
};





//Time Complexity - O(NlogN) and Space - O(LogN)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
    
    int midTerm(ListNode* head, int mid){
        while(mid-- > 0)
            head = head->next;
        
        return head->val;
    }
    
    TreeNode* buildTree(ListNode* nums,int srt, int end){
        if(srt > end) return NULL;
        
        int mid = srt + (end-srt)/2;
    
        TreeNode* node = new TreeNode( midTerm(nums,mid) );
        
        node->left = buildTree(nums,srt,mid-1);
        node->right = buildTree(nums,mid+1,end);
        
        return node;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        int  size=0;
        ListNode* tmp = head;
        while(tmp){
            size++;
            tmp = tmp->next;
        }
        
        return buildTree(head,0,size-1);
    }
};

