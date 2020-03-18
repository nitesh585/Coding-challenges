/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

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
    ListNode* partition(ListNode* head, int x) {
        ListNode l(0) ;
        ListNode g(0);
        ListNode* l1 = &l;
        ListNode* g1 = &g;
        while(head){
            if(head->val < x){
                l1->next = head;
                l1 = l1->next;
            }else{
                g1->next = head;
                g1 = g1->next;
                
            }
             head = head->next;
        }
        g1->next = NULL;
        l1->next = g.next;
        return l.next;
    }
};
