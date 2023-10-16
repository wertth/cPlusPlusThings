//
// Created by miaohaochu on 2023/9/28.
//

#ifndef CPLUSPLUSTHINGS_ROME_2_INTEGER_H
#define CPLUSPLUSTHINGS_ROME_2_INTEGER_H
#include "iostream"
#include "vector"
#include "string"
#include "unordered_map"
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        unordered_map<string, int> map {
                {"I", 1},
                {"IV", 4},
                {"IX", 9},

                {"V", 5},

                {"X", 10},
                {"XL", 40},
                {"XC", 90},

                {"L", 50},
                {"C", 100},
                {"CD", 400},
                {"CM", 900},

                {"D", 500},
                {"M", 1000}
        };
        auto begin = s.begin(), end = s.end() - 1;
        while(begin <= end) {
            char val = *begin;
            switch (val) {
                case 'I':
                case 'X':
                case 'C':
                    if(begin + 1 <= end) {
                        string expect = string(1,val) + *(begin + 1);
                        if(map.contains(expect)) {
                            res+=map.at(expect);
                            begin+= 2;
                        }else {
                            res += map.at(string(1,val));
                            begin++;
                        }
                    } else {
                        res += map.at(string(1,val));
                        begin++;
                    }
                    break;
                default:
                    res += map.at(string(1,val));
                    begin++;
            }
        }
        return res;
    }
};
#endif //CPLUSPLUSTHINGS_ROME_2_INTEGER_H
