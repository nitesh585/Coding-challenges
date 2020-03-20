/*
Write a program to find the node at which the intersection of two singly linked lists begins.

Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: 
The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. 
From the head of B, it reads as [5,0,1,8,4,5]. 
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tmp1 = headA;
        ListNode* tmp2 = headB;
        int cnt1=0,cnt2=0;
        
        while(tmp1){
            cnt1++;
            tmp1 = tmp1->next;
        }
        while(tmp2){
            cnt2++;
            tmp2 = tmp2->next;
        }
        int dif = cnt1-cnt2;
        if(dif>0){
            tmp1 = headA;
            tmp2 = headB;
        }else{
            tmp1 = headB;
            tmp2 = headA;
        }
       dif = abs(dif);
        for(int i=0;i<dif;i++){
            tmp1 = tmp1->next;
        }
        while(tmp1 && tmp1!=tmp2){
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        
        return tmp1;
        
    }
};


