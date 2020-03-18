/*
Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ≤ m ≤ n ≤ length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL

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
    
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head) return NULL;
        
        ListNode* pre = NULL;
        ListNode* curr = head;
    
        while(m>1){
            pre = curr;
            curr  = curr->next;
            n--;
            m--;
        }
        
        ListNode* start =  pre;
        ListNode* tail = curr;
        
        ListNode* tmp = NULL;
        while(n>0){
            tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
            n--;
            
        }
    
        if(start){
            start->next = pre;
        }else{
            head = pre;
        }
        
        tail->next = curr;
        cout<<head->val;
        return head;
    }
};
