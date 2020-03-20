/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode odd(0);
        ListNode even(0);
        
        ListNode* o = &odd;
        ListNode* e = &even;
        int i=1;
        while(head){
            if(i%2==0){
                e->next = head;
                e = e->next;
            }else{
                o->next = head;
                o = o->next;
            }
            head = head->next;
            i++;
        }
        o->next = even.next;
        e->next = NULL;
        
        return odd.next;
        
    }
};
