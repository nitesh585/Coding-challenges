/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Return the linked list sorted as well.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
*/


//Using HashMap , Space- O(N)
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
        
        map<int,int> m;
        ListNode* tmp = head;
        while(tmp!=NULL){
            m[tmp->val]++;
            tmp = tmp->next;
        }
        tmp = head;
        ListNode* curr = new ListNode(0);
        head = curr;
        while(tmp!=NULL){
            if(m[tmp->val] == 1){
                ListNode* t = new ListNode(tmp->val);
                curr->next = t;
                curr = curr->next;
            }
            tmp = tmp->next;
        }
        
        return head->next;
    }
};



// Space - O(1)

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
        ListNode* tmp = head;
        ListNode* dummy =  new ListNode(0);
        ListNode* res = dummy;
        bool flag = true;
        
        while(tmp){
            while( tmp->next && tmp->val==tmp->next->val){
                tmp = tmp->next;
                flag  = false;
            }
            if(!flag){
                flag = true;
            }else{
                 dummy->next = new ListNode(tmp->val);
                 dummy = dummy->next;
            }
            tmp = tmp->next;
        }
        return res->next;
    }
    
};
