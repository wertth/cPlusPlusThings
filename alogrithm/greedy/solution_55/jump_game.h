//
// Created by miaohaochu on 2023/9/22.
//

#ifndef CPLUSPLUSTHINGS_JUMP_GAME_H
#define CPLUSPLUSTHINGS_JUMP_GAME_H
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static bool backTrace(vector<int>&  nums,vector<int> &status,int position,  int end) {
        if(status[position] == 1) return false;
        if(position > end) return true;

        int maxJumpDistance = nums[position];

        if(position == end) return true;
        if(position < end && maxJumpDistance <= 0) return false;
        if(position < end && maxJumpDistance + position - 1 >= end) return true;
        status[position] = 1;
        bool flag = false;
        for(int i = 1; i <= maxJumpDistance; i++) {
            position += i;
            flag = backTrace(nums, status, position, end);
            if(flag) return flag;
            position -= i;
        }
        return flag;
    }
    static bool canJump(vector<int>& nums) {
        int position = 0, size = nums.size();
        vector<int> status(nums.size());
        return Solution::backTrace(nums ,status, position, size - 1);
    }
};
#endif //CPLUSPLUSTHINGS_JUMP_GAME_H
