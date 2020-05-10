/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4

Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5


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
 
    ListNode* merge(ListNode* a, ListNode* b){
        ListNode* c = new ListNode(-1);
        ListNode* res = c;
        while(a && b){
            if(a->val > b->val){
                c->next = new ListNode(b->val);
                b = b->next;
            }else{
                c->next = new ListNode(a->val);
                a = a->next;
            }
            c = c->next;
        }
        
        c->next = a ? a:b;
        
        return res->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
    
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;
        
        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next= NULL;
        
        return merge(sortList(head), sortList(slow));
    }
};
