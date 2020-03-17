/*
Given a n-ary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

Example 1:

Input: root = [1,null,3,2,4,null,5,6]
Output: 3

*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    
    int maxh = INT_MIN;
    
    int maxDepth(Node* root) {
        if(!root) return 0;
        
        int tmp=0;
        for(auto i  = root->children.begin() ; i!=root->children.end() ; i++){
            tmp = max(maxDepth(*i),tmp);
        }
        
        return max(maxh,tmp)+1;
        
    }
};
