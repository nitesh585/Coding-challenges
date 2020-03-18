/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        
        ListNode* curr =head;
        while(curr->next != NULL){
            if(curr->val == curr->next->val){
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};
