#pragma once
#include<stack>
class MyQueue {
private:
    std::stack<int> in;
    std::stack<int> out;
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int r = peek();
        out.pop();
        return r;

    }

    /** Get the front element. */
    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                int o = in.top();
                out.push(o);
                in.pop();
            }

        }
        int o = out.top();
        return o;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
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

