//
// Created by miaohaochu on 2023/9/23.
//
#include "iostream"
#include "vector"

using namespace std;
#ifndef CPLUSPLUSTHINGS_JUMP_GAME_II_H
#define CPLUSPLUSTHINGS_JUMP_GAME_II_H
class Solution {
public:
    int jump(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) return 0;
        vector<int> dp(size);
        dp[0] = 0;
        for(int i = 0; i < size; i++) {
            int maxJumpDistance = nums[i];
            for(int j = 1; j <= maxJumpDistance && i+j < size ;j++) {
                if(dp[i + j] != 0) continue;
                dp[i+j] = dp[i] + 1;
            }
        }
        return dp.back();
    }
};
#endif //CPLUSPLUSTHINGS_JUMP_GAME_II_H
