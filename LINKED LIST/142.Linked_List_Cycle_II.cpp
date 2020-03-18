/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

	  //find the meeting point of slow and fast pointer
        while(slow){
            if(!fast || !fast->next ){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                break;
            }
        }
        
        slow = head;
        //move slow and fast with one step to get the starting point of the cycle
	  while(slow){
            if(slow==fast){
                return slow;
            }
            slow = slow->next;
            fast =  fast->next;
        }
        
        return NULL;
    }
};
