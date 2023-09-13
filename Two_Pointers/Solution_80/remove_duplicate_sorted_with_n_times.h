//
// Created by miaohaochu on 2023/9/11.
//

#ifndef CPLUSPLUSTHINGS_REMOVE_DUPLICATE_SORTED_WITH_N_TIMES_H
#define CPLUSPLUSTHINGS_REMOVE_DUPLICATE_SORTED_WITH_N_TIMES_H
#include "iostream"
#include "vector"
#include "cmath"
class Solution {
public:
    template<typename T>
    static int removeExtraDuplicateWithNTimes(std::vector<T> &vec, int n = 1) {
        int left = 0, right = 0, len = vec.size();
        while(left < len && right < len) {
            if(vec[right] == vec[left]) right++;
            else {
                int new_start = std::min(right, left + n);
                int temp_right = right;
                left = new_start;
                int diff = (temp_right - new_start);
                if(new_start != temp_right) {
                    while(temp_right < len) {
                        vec[new_start++] = vec[temp_right++];
                    }
                    len -= diff;
                    right = left;
                }

//                left += std::min((right - left), n);
//                vec[left] = vec[right];
            }
        }
        //std::min(right, left+n)
        return std::min(left+n,right);
    };
};


#endif //CPLUSPLUSTHINGS_REMOVE_DUPLICATE_SORTED_WITH_N_TIMES_H
