//
// Created by miaohaochu on 2023/9/26.
//

#ifndef CPLUSPLUSTHINGS_H_CITATIONS_H
#define CPLUSPLUSTHINGS_H_CITATIONS_H
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static int hIndex(vector<int>& citations) {
        int len = citations.size();
        sort(citations.begin(), citations.end(), greater<int>());
        int maxHExpect = len;
        while(maxHExpect > 0) {
            int greaterThanCount = 0; // 记录大于等于maxHExpect 的次数
            for(int &elem : citations) {
                if(elem >= maxHExpect) greaterThanCount++;
            }
            if(greaterThanCount == maxHExpect) return maxHExpect;
            else maxHExpect--;
        }
        return 0;

    }
};
#endif //CPLUSPLUSTHINGS_H_CITATIONS_H
