//
// Created by miaohaochu on 2023/9/21.
//

#ifndef CPLUSPLUSTHINGS_WIGGLE_SUBSEQUENCE_H
#define CPLUSPLUSTHINGS_WIGGLE_SUBSEQUENCE_H
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        vector<int> diff;
        for(int i = 0; i < size - 1; i++) {
            if(nums[i+1] != nums[i]) {
                diff.push_back(nums[i+1] - nums[i]);
            }
        }
        if(diff.size() == 0) {
            return 1;
        } else if(diff.size() == 1){
            return diff[0] == 0 ? 1 : 2;
        }
        auto left = diff.begin(), right = left + 1;
        while( right != diff.end() ) {
            int last = *(right - 1), cur = *right;
            if(cur * last > 0) {
                last += cur;
                right  = diff.erase(right);
            }else {
                right ++;
            }
        }
        return diff.size() + 1;

    }
};
#endif //CPLUSPLUSTHINGS_WIGGLE_SUBSEQUENCE_H
