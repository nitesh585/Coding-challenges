/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// Approach 1 : Simplest
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        
        while(l1!=NULL && l2!=NULL){ 
            ListNode* tmp = new ListNode(0);
            if(l1->val <= l2->val){
                tmp->val = l1->val;
                l1 = l1->next;
            }else{
                tmp->val = l2->val;
                l2 = l2->next;
            }
            curr->next = tmp;
            curr = curr->next;
            
        }
        
        while(l1!=NULL){
            ListNode* tmp = new ListNode(l1->val);
            curr->next = tmp;
            curr = curr->next;
            l1 = l1->next;
        }
        
        while(l2!=NULL){
            ListNode* tmp = new ListNode(l2->val);
            curr->next = tmp;
            curr = curr->next;
            l2 = l2->next;
        }
        return head->next;
    }
};


// Approach 2 : Efficient

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        
        while(l1!=NULL || l2!=NULL){ 
            ListNode* tmp = new ListNode(0);
            if(l1==NULL) {
                // if end of the list 1 link remaining list 2 to curr list
                curr->next = l2;
                break;
                
            }else if(l2==NULL){
                // if end of the list 2 link remaining list 1 to curr list
                curr->next = l1;
                break;
                
            }else if( l1->val <= l2->val){
                tmp->val = l1->val;
                l1 = l1->next;
            }else{
                tmp->val = l2->val;
                l2 = l2->next ;
            }
            curr->next = tmp;
            curr = curr->next;   
        }
        
        return head->next;
    }
};
