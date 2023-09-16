//
// Created by miaohaochu on 2023/9/16.
//

#ifndef CPLUSPLUSTHINGS_KTH_BIG_NUM_H
#define CPLUSPLUSTHINGS_KTH_BIG_NUM_H
#include "iostream"
#include "vector"
#include "queue"
using namespace std;
class Solution {
public:
    static int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> bigHeap;
        for(auto &i: nums) {
            bigHeap.push(i);
        }

        for(int i = 0 ; i < k  ; i++ ) {
            if(i == k - 1) {
                return bigHeap.top();
            }
            bigHeap.pop();
        }
    }
};
#endif //CPLUSPLUSTHINGS_KTH_BIG_NUM_H
