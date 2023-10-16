//
// Created by miaohaochu on 2023/10/14.
//

#ifndef CPLUSPLUSTHINGS_PALINDROME_H
#define CPLUSPLUSTHINGS_PALINDROME_H
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> vec;
        for(char elem: s) {
            if(elem <= 'Z' && elem >= 'A') {
                vec.push_back(elem - 'A' + 'a');
            } else if((elem <= 'z' && elem >= 'a' )||( elem <= '9' && elem >= '0')) {
                vec.push_back(elem);
            }
        }

        int left = 0, right = vec.size() - 1;
        while(left <= right && left <= vec.size() - 1 && right >= 0) {
            if(vec[left] == vec[right]){
                left ++ ;
                right--;
            } else {
                return false;
            }
        }
        return true;
    }
};
#endif //CPLUSPLUSTHINGS_PALINDROME_H
