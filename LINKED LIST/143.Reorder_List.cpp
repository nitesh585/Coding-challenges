/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.

Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.

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
      
    void reorderList(ListNode* head) {
        deque<ListNode*> dq;
        
        while(head){
           dq.push_back(head);
           head = head->next;
        } 
        
        while(!dq.empty()){
            if(dq.size()<=2) break;
            
            ListNode* a = dq.front();
            ListNode* b = dq.back();
            dq.pop_front();
            dq.pop_back();
            
            dq.back()->next = NULL;
            
            ListNode* tmp = a->next;  
            a->next = b;
            b->next = tmp;
        }
        
    }
};
