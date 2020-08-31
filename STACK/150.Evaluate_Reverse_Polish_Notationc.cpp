/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Note:

    Division between two integers should truncate toward zero.
    The given RPN expression is always valid. That means the expression would always evaluate to a result and there won't be any divide by zero operation.

Example 1:

Input: ["2", "1", "+", "3", "*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: ["4", "13", "5", "/", "+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
Output: 22
Explanation: 
  ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22
*/

class Solution {
public:
    
    void add(stack<int>& stk){
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();
        
        stk.push(a+b);
    }
    
    
    void subtract(stack<int>& stk){
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();
        
        stk.push(b-a);
    }
    
    
    void multiply(stack<int>& stk){
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();
        
        stk.push(a*b);
    }
    
    
    void divide(stack<int>& stk){
        int a = stk.top();
        stk.pop();
        int b = stk.top();
        stk.pop();
        
        stk.push(b/a);
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string token:tokens){
            
            if(token=="+"){
                add(stk);
            }else if(token=="-"){
                subtract(stk);
            }else if(token=="*"){
                multiply(stk);
            }else if(token=="/"){
                divide(stk);
            }else{
                stk.push(stoi(token));    
            }
        }
        
        return stk.top();
    }
};
