/*
225. Implement Stack using Queues
Implement a last-in-first-out (LIFO) stack using only two queues. 
The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
*/

#include <queue>

class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        myQueue.push(x);
        for (int i = 0; i < myQueue.size() - 1; ++i) {
            myQueue.push(myQueue.front());
            myQueue.pop();
        }
    }
    
    int pop() {
        int tmp = myQueue.front();
        myQueue.pop();
        return tmp;
    }
    
    int top() {
        return myQueue.front();
    }
    
    bool empty() {
        return myQueue.empty();
    }

private:
    std::queue<int> myQueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

/*
Example 1:

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
*/