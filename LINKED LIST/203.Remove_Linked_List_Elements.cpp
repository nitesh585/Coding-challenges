/*
Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5

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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* tmp = head;
        ListNode* curr = new ListNode(0);
        head  =curr;
        while(tmp!=NULL){
            if(tmp->val!=val){
                ListNode* t = new ListNode(tmp->val);
                curr->next = t;
                curr = curr->next;
            }
            tmp = tmp->next;
        }
        
        return head->next;;
    }
};
