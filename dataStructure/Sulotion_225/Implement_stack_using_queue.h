//
// Created by miaohaochu on 2023/9/13.
//
#include "iostream"
#include "queue"
using namespace std;

class MyStack {
private:
    queue<int> _data;
public:
    MyStack() {};
    void push(int x) {
        queue<int> temp;
        while(!_data.empty()) {
            temp.push(_data.front());
            _data.pop();
        }
        _data.push(x);
        while(!temp.empty()) {
            _data.push(temp.front());
            temp.pop();
        }
    }
    int pop() {
        if(!_data.empty()) {
            int a = _data.front();
            _data.pop();
            return a;
        }
        return -1;
    }
    int top() {
        return _data.front();
    }
    bool empty() {
        return _data.empty();
    }
};