//
// Created by miaohaochu on 2023/9/16.
//
#include "iostream"
#include "is_valid_pop_order.h"

using namespace std;

int main() {
    vector<int> a = {1,2,3,4,5}, b = {4,5,3,2,1};
    vector<int> c{},d{};
    Solution::validateStackSequences(a,b);
    Solution::validateStackSequences(c,d);
}
