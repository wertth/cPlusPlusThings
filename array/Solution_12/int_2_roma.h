//
// Created by miaohaochu on 2023/9/29.
//

#ifndef CPLUSPLUSTHINGS_INT_2_ROMA_H
#define CPLUSPLUSTHINGS_INT_2_ROMA_H
#include "iostream"
#include "vector"
#include "map"
#include "algorithm"
using namespace std;
typedef pair<int, string> PAIR;
bool cmp(const PAIR & pair1, const PAIR & pair2) {
    return pair1.first < pair2.first;
}
class Solution {
public:
    string intToRoman(int num) {
        string res = "";
//        bool(*fn_ptr) (const PAIR & pair1, const PAIR & pair2 ) = cmp;
//        bool(*)(const PAIR & pair1, const PAIR & pair2)
        map<int, string, greater<int>> val2RomanMap {
                {1, "I"},
                {4, "IV"},
                {5, "V"},
                {9, "IX"},
                {10, "X"},
                {40, "XL"},
                {50, "L"},
                {90, "XC"},
                {100, "C"},
                {400, "CD"},
                {500, "D"},
                {900, "CM"},
                {1000, "M"},
        };
        auto begin = val2RomanMap.begin(),end = val2RomanMap.end() ;
        while(num) {
            while(begin!=end) {
                if(num >= begin->first) {
                    num -= begin->first;
                    res += begin->second;
                } else {
                    begin++;
                }
            }
        }
        return res;
    }

};
#endif //CPLUSPLUSTHINGS_INT_2_ROMA_H
