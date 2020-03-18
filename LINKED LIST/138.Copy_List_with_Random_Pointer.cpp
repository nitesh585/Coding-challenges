/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.

The Linked List is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

    val: an integer representing Node.val
    random_index: the index of the node (range from 0 to n-1) where random pointer points to, or null if it does not point to any node.

 

Example 1:

Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node* tmp = head;
        map<Node*,Node*> mymap ;
        while(tmp){
            Node *copy = new Node(tmp->val);
            mymap[tmp] = copy;
            tmp = tmp->next;
        }
        
        for(auto i = mymap.begin();  i!=mymap.end() ; i++){
            Node* old = i->first;
            Node* copy = i->second;
            
            if(old->next) copy->next = mymap[old->next];
            
            if(old->random) copy->random = mymap[old->random];
        }
        
        
        return mymap[head];
    }
};


