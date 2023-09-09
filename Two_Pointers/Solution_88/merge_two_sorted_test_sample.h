//
// Created by miaohaochu on 2023/9/9.
//

#ifndef CPLUSPLUSTHINGS_MERGE_TWO_SORTED_TEST_SAMPLE_H
#define CPLUSPLUSTHINGS_MERGE_TWO_SORTED_TEST_SAMPLE_H
#include <iostream>
#include "vector"
#include "cstdlib"
class Sample {
public:
    // capacity: 指定数组长度 count: 指定生成 无count默认等于capacity
    static std::vector<int> genRandomNums(int capacity,int from = 0, int end = 10, int count = -1);
};

std::vector<int> Sample::genRandomNums(int capacity,int from, int end, int count) {
    if(capacity < 0) return std::vector<int>(0);
    if(count < 0) count = capacity;
    std::vector<int> vec (capacity);

    srand((int) time(0));
    for(int i = 0; i < count; i++) {
        vec[i] = rand() % (end - from + 1) + from ; // gen a num with specific range
    }
    return vec;
}

#endif //CPLUSPLUSTHINGS_MERGE_TWO_SORTED_TEST_SAMPLE_H
