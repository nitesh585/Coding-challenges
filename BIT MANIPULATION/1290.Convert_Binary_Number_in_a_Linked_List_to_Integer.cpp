/*
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

Return the decimal value of the number in the linked list.

 

Example 1:

Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
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
    int getDecimalValue(ListNode* head) {
        int size = 0;
        ListNode* tmp = head;
        while(tmp!=NULL){
            size++;
            tmp = tmp->next;
        }

        tmp = head;
        int res=0;
        while(tmp!=NULL){
            res += ((tmp->val)*pow(2,size-1));
            size--;
            tmp = tmp->next;
        }
        return res;
        
    }
};
