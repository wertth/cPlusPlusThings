//
// Created by miaohaochu on 2023/9/22.
//
#include "iostream"
#include "vector"
#include "jump_game.h"
using namespace std;

int main() {
    vector<int> a = {2,3,1,1,4};

    cout << Solution::canJump(a);

    vector<int> b = {3,2,1,0,4};
    cout << Solution::canJump(b);
}