//
// Created by miaohaochu on 2023/9/14.
//
#include "min_stack.h"
#include "iostream"

using namespace std;

int main() {
    MinStack m;
    m.push(1);
    m.push(1000);
    m.getMin();
    m.push(4);
    m.getMin();
    return 0;
}