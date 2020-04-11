/*
Implement the following operations of a queue using stacks.

    push(x) -- Push element x to the back of queue.
    pop() -- Removes the element from in front of queue.
    peek() -- Get the front element.
    empty() -- Return whether the queue is empty.

Example:

MyQueue queue = new MyQueue();

queue.push(1);
queue.push(2);  
queue.peek();  // returns 1
queue.pop();   // returns 1
queue.empty(); // returns false
*/

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> stk1;
    stack<int> stk2;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        stk1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int t = stk2.top();
        stk2.pop();
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return t;
    }
    
    /** Get the front element. */
    int peek() {
        
        while(!stk1.empty()){
            stk2.push(stk1.top());
            stk1.pop();
        }
        int t = stk2.top();
        while(!stk2.empty()){
            stk1.push(stk2.top());
            stk2.pop();
        }
        return t;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stk1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
