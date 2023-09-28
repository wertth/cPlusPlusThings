//
// Created by miaohaochu on 2023/9/27.
//

#ifndef CPLUSPLUSTHINGS_PRODUCTEXCLUDEITSELF_H
#define CPLUSPLUSTHINGS_PRODUCTEXCLUDEITSELF_H
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        if(len == 0) return {};
        vector<int> ans(len, 1);
        int temp = 1;
        for(int i = 1; i < len ; i++) {
            ans[i] = ans[i-1] *nums[i -1];
        }
        for(int j = len - 2; j >= 0 ; j--) {
            temp *= nums[j + 1];
            ans[j] *= temp;
        }
        return ans;
    }
};
#endif //CPLUSPLUSTHINGS_PRODUCTEXCLUDEITSELF_H
