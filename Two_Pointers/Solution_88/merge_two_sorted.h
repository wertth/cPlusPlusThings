//
// Created by miaohaochu on 2023/9/7.
//

#ifndef CPLUSPLUSTHINGS_MERGE_TWO_SORTED_H
#define CPLUSPLUSTHINGS_MERGE_TWO_SORTED_H
#include "iostream"
#include "vector"
class Solution {
    public :
        static void merge(std::vector<int> &v1, int m,  std::vector<int> &v2, int n);
        static void display(std::vector<int> & v);
};

void Solution::merge(std::vector<int> &v1, int m,  std::vector<int> &v2, int n) {
    std::vector<int> vec (v1.begin(), v1.begin() + m);
    int mergeIndex = 0, v1_i = 0, v2_i = 0;
    while(mergeIndex < (m+n)) {
        if(v1_i == m && v2_i < n) {
            v1[mergeIndex] = v2[v2_i++];
        }  else if (v2_i == n && v1_i < m) {
            v1[mergeIndex] = vec[v1_i++];
        } else {
            vec[v1_i] > v2[v2_i]
                ? v1[mergeIndex] = v2[v2_i++]
                : v1[mergeIndex] = vec[v1_i++];
        }
        mergeIndex++;
    }
//    auto v1_iter =  vec.begin() , v2_iter= v2.begin();
//    while(v1_iter <= vec.end() || v2_iter <= v2.end()) {
//        if(v1_iter == vec.end() && v2_iter < v2.end()) {
//            v1[mergeIndex] = *(v2_iter++);
//        } else if(v2_iter == v2.end() && v1_iter <= vec.end()) {
//            v1[mergeIndex] = *(v1_iter++);
//        } else {
//            (*v1_iter) > (*v2_iter)
//            ? v1[mergeIndex] = (*(v2_iter++))
//            : v1[mergeIndex] = (*(v1_iter++));
//
//        }
//        mergeIndex++;
//    }
    Solution::display(v1);
}

void Solution::display(std::vector<int> &v) {
    for(auto i : v) {
        std::cout<< i << ' ';
    }
    std::cout << std::endl;
}
#endif //CPLUSPLUSTHINGS_MERGE_TWO_SORTED_H
