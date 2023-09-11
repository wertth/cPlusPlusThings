//
// Created by miaohaochu on 2023/9/10.
//

#ifndef CPLUSPLUSTHINGS_REMOVE_ELEMENT_IN_PLACE_H
#define CPLUSPLUSTHINGS_REMOVE_ELEMENT_IN_PLACE_H
#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
class Solution {
public:
    static int removeElement(vector<int>& nums, int val);
};

int Solution::removeElement(vector<int> &nums, int val) {
    // 1. sort
    sort(nums.begin(), nums.end(), less<int>());

    int left = 0, right = 0, len = nums.size();

    int count = 0;

    while(left < len && right < len) {
        if(nums[right] != val) {
            nums[left++] = nums[right];
        } else {
            count++;
        }
        right++;
    }
    nums.resize(len - count); // 可加可不加
    return len - count;
}
#endif //CPLUSPLUSTHINGS_REMOVE_ELEMENT_IN_PLACE_H
