//
// Created by miaohaochu on 2023/9/13.
//
#include "Implement_stack_using_queue.h"
#include "iostream"
using namespace std;

int main() {
    MyStack s;
    s.push(1);
    cout<< s.top() << endl;
    s.push(2);
    cout<< s.top() << endl;
    s.push(3);
    cout<< s.top() << endl;
    cout<< s.pop() << endl;
    cout<< s.empty() << endl;
}
