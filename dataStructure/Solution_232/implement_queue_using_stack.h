//
// Created by miaohaochu on 2023/9/14.
//

#ifndef CPLUSPLUSTHINGS_IMPLEMENT_QUEUE_USING_STACK_H
#define CPLUSPLUSTHINGS_IMPLEMENT_QUEUE_USING_STACK_H
#include "iostream"
#include "stack"
using namespace std;
class MyQueue {
private:
    stack<int> _data;
public:
    MyQueue() {
    }

    void push(int x) {
        stack<int> temp;
        while(!_data.empty()) {
            temp.push(_data.top());
            _data.pop();
        }
        _data.push(x);
        while(!temp.empty()) {
            _data.push(temp.top());
            temp.pop();
        }
    }

    int pop() {
        int x = _data.top();
        _data.pop();
        return x;
    }

    int peek() {
        return _data.top();
    }

    bool empty() {
        return _data.empty();
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
#endif //CPLUSPLUSTHINGS_IMPLEMENT_QUEUE_USING_STACK_H
