/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Example:

Input:
[
  1->4->5,
  1->3->4,
  2->6
]
Output: 1->1->2->3->4->4->5->6

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int> queue;
        for(int i=0;i<lists.size();i++){
            ListNode* tmp = lists[i];
            while(tmp!=NULL){
                queue.push((-1)*tmp->val);
                tmp = tmp->next;
            }
        }
        
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while(!queue.empty()){
            int p = queue.top();
            queue.pop();
            ListNode*t = new ListNode(p*(-1));
            curr->next = t;
            curr = curr->next;
        }
        
        return head->next;
    }
};
