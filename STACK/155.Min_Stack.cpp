/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

 

Example:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> Returns -3.
minStack.pop();
minStack.top();      --> Returns 0.
minStack.getMin();   --> Returns -2.

*/

class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> stk2;
    MinStack() {   
    }
    
    void push(int x) {
        stk.push(x);
        if(!stk2.empty()){
            int t = stk2.top();
            int t2 = stk.top();
            if(t2<t){
                stk2.push(t2);
            }else{
                stk2.push(t);
            }
        }else{
            stk2.push(x);
        }
    }
    
    void pop() {
        int t = stk.top();
        int t2 = stk2.top();
        stk2.pop();
        stk.pop();
    }
    
    int top() {
        int t =  stk.top();
        return t;
    }
    
    int getMin() {
        int t = stk2.top();
        return t;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
