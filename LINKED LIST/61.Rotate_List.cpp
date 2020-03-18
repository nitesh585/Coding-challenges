/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Example 1:

Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL

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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        
        int size=0;
        ListNode* tmp = head;
        while(tmp->next!=NULL){
            size++;
            tmp = tmp->next;
        }
        
 	  size++;
        k = (size - (k%size));
        ListNode* tmp2 = new ListNode(0);
        tmp2->next = head;
        
	  while(k--) tmp2  = tmp2->next;
        
        
        tmp->next = head;
        head = tmp2->next;
        tmp2->next = NULL;
        
        return head;
    }
};
