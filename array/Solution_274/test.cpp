//
// Created by miaohaochu on 2023/9/26.
//
#include "iostream"
#include "h_citations.h"
using namespace std;

int main() {
    vector<int> a = {3,0,6,1,5};
    vector<int> b ={1,3,1};

    cout<< Solution::hIndex(a);
    cout<< Solution::hIndex(b);
}
