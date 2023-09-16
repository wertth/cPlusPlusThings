//
// Created by miaohaochu on 2023/9/16.
//

#ifndef CPLUSPLUSTHINGS_ROTATE_ARRAY_H
#define CPLUSPLUSTHINGS_ROTATE_ARRAY_H
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static void rotate(vector<int>& nums, int k) {
        if(nums.size() <= 1) return;
        k = k % nums.size();
        auto first = nums.begin(), last = nums.end() - 1, last_k = last - k;
        vector<int> last_k_element(last_k + 1, last + 1);

//        vector<vector<int> > vec {{1,2,3},{1,2,3}};
        while(last_k >= first) {
            *(last--) = *(last_k--);
        }
        while(k>0) {
            *(first + k - 1) = last_k_element[k - 1];
            k--;
        }
//        for(int i = 0; i < k ; i++ ) {
//            Solution::rotateByLastPosition(nums);
//        }
    }
    static void rotateByLastPosition(vector<int> & vec) {
        if(vec.size() <= 1) {
            return ;
        }
        int temp = 0;
        auto begin = vec.begin(), end = vec.end() - 1;
        temp = *end;
        while(end!=begin) {
            *end = *(end - 1);
            end--;
        }
        *begin = temp;
    }
};
#endif //CPLUSPLUSTHINGS_ROTATE_ARRAY_H
