/*
Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL){
            return true;
        }
        int size = 0;
        ListNode* tmp = head;
        while(tmp!=NULL){
            size++;
            tmp = tmp->next;
        }
        int ar[size];
        for(int i=0;i<size;i++){
            ar[i] = head->val;
            head = head->next;
        }
        
        for(int i=0;i<size/2;i++){
            if(ar[i] != ar[size-i-1] ){
                return false;
            }
        }
        
        return true;
    }
};
