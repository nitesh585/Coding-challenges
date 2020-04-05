/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.

Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:

Input: "()[]{}"
Output: true

Example 3:

Input: "(]"
Output: false

Example 4:

Input: "([)]"
Output: false

*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        char x;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='{' || s[i]=='[' || s[i]=='(' ){
                stk.push(s[i]);
            }else{
           
                if(stk.empty()){
                    return false;
                }
                
                x = stk.top();
                stk.pop();
                
                if((x=='(') && (s[i]==']' || s[i]=='}' ) ){
                    return false;
                }
            
                if((x=='{') && (s[i]==']' || s[i]==')' )   ){
                    return false;
                }
            
                if((x=='[') && (s[i]==')' || s[i]=='}' ) ){
                    return false;
                }
            }
        }
        
        return stk.empty();
    }
};
