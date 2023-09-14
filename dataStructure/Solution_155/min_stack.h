//
// Created by miaohaochu on 2023/9/14.
//

#ifndef CPLUSPLUSTHINGS_MIN_STACK_H
#define CPLUSPLUSTHINGS_MIN_STACK_H
#include "iostream"
#include "stack"
using namespace std;
//class MinStack {
//private:
//    stack<int> _data;
//    stack<int> _min;
//public:
//    MinStack() {};
//    void push(int x) {
//        _data.push(x);
//        if(!_min.empty()) {
//            _min.push(min(_min.top(), x));
//        }
//    }
//    void pop() {
//        _data.pop();
//        _min.pop();
//    }
//    int top() {
//        return _data.top();
//    }
//    int getMin() {
//        return _min.top();
//    }
//};


class MinStack {
private:
    stack<int> _data;
    stack<int> _min;
public:
    MinStack() {

    }

    void push(int val) {
        _data.push(val);
//        if(!_min.empty() && _min.top() > val) {
//            _min.push(val);
//        }
        if(!_min.empty()) {
            _min.push(min(_min.top() , val));
        } else {
            _min.push(val);
        }

    }

    void pop() {
        _data.pop();
        _min.pop();
    }

    int top() {
        return _data.top();
    }

    int getMin() {
        return _min.top();
    }
};
#endif //CPLUSPLUSTHINGS_MIN_STACK_H
