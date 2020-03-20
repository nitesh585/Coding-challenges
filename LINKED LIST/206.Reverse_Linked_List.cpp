/*
Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Iterative :
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        while(curr!=NULL){
            head = curr->next;
            curr->next = prev;
            prev = curr;
            curr = head;
        }
        return prev;
    }
};


// Recursive :
class Solution {
public:
    
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* p  = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        
        return p;
    }
};

