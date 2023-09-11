//
// Created by miaohaochu on 2023/9/11.
//

#ifndef CPLUSPLUSTHINGS_REMOVE_DUPLICATE_SORTED_H
#define CPLUSPLUSTHINGS_REMOVE_DUPLICATE_SORTED_H
#include "vector"
using namespace std;
class Solution {
public:
    // sorted: nums
    static int removeDuplicates(vector<int>& nums) {
//        auto left = nums.begin(), right = nums.begin(), end = nums.end();
//        while(left != end && right != end) {
//            if(*left == *right) {
//                right++;
//            } else {
//                left++;
//                *left = *right;
//            }
//        }
//        return left - nums.begin() + 1;

        int left = 0, right = 0, len = nums.size();
        while(left < len && right < len) {
            if(nums[right] == nums[left]) {
                right++;
            } else {
                left++;// 仅保留一个重复的数字
                nums[left] = nums[right];
            }
        }
        return left + 1;

    }

};


#endif //CPLUSPLUSTHINGS_REMOVE_DUPLICATE_SORTED_H
