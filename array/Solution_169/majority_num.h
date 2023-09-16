//
// Created by miaohaochu on 2023/9/14.
//

#ifndef CPLUSPLUSTHINGS_MAJORITY_NUM_H
#define CPLUSPLUSTHINGS_MAJORITY_NUM_H
#include "iostream"
#include "vector"
#include "unordered_map"
using namespace std;
class Solution {
public:
    static int majorityElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        sort(nums.begin(), nums.end(), less<int>());
        unordered_map<int,int> map;
        for(int i = len/2; i<len; i++) {
            int num = nums[i];
            if(map.find(num) == map.end()) {
                map.insert(pair<int,int>(num, 1));
            } else {
                map[num] ++;
                if(map[num] > len / 2) return num;
            }


        }


//        for(auto &i : nums) {
//
//        }
        return -1;
    }
};
#endif //CPLUSPLUSTHINGS_MAJORITY_NUM_H
