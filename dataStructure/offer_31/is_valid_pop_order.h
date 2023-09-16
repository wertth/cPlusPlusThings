//
// Created by miaohaochu on 2023/9/16.
//

#ifndef CPLUSPLUSTHINGS_IS_VALID_POP_ORDER_H
#define CPLUSPLUSTHINGS_IS_VALID_POP_ORDER_H
#include "iostream"
#include "vector"
#include "queue"
#include "stack"
using namespace std;
class Solution {
public:
    static bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if(pushed.size() != popped.size()) return false;
        if(popped.empty() && pushed.empty()) return true;
        queue<int> orderQueue;
        // pushed to initialize the orderQueue
        for(auto &i : popped) {
            orderQueue.push(i);
        }
        stack<int> assistStack;

        auto pushedEnd = pushed.end() - 1, pushedStart = pushed.begin();
        while (pushedStart <= pushedEnd) {
            assistStack.push(*pushedStart);
            while(!assistStack.empty()  && assistStack.top() == orderQueue.front()) {

                assistStack.pop();
                orderQueue.pop();
            }
            pushedStart ++;
        }
        return assistStack.empty();

    }
};
#endif //CPLUSPLUSTHINGS_IS_VALID_POP_ORDER_H
