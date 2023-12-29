/*
 * @lc app=leetcode.cn id=290 lang=cpp
 * @lcpr version=30112
 *
 * [290] 单词规律
 */


// @lcpr-template-start
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> arr = vector<string>(26);
        vector<string> words;
        string temp_word;
        std::for_each(s.begin(), s.end(), [&](char& c) {
            if (c == ' ') {
                if (!temp_word.empty()) {
                    words.push_back(temp_word);
                    temp_word.clear();
                }
            } else {
                temp_word += c;
            }
        });
        if (!temp_word.empty()) {
            words.push_back(temp_word);
        }

        if(words.size() != pattern.size()) return false;

        for(int i = 0; i < words.size(); i++) {
            int pos = pattern[i] - 'a';
            if((arr[pos]).empty()) {
                arr[pos] = words[i];
            } 

            if(arr[pos] != words[i]) return false;
            vector<string>::const_iterator iter = find(arr.begin(), arr.end(), words[i]);
            if((distance(arr.cbegin(), iter)) != pos) return false;
        }

        return true;

    }
};
// @lc code=end



/*
// @lcpr case=start
// "abba"\n"dog cat cat dog"\n
// @lcpr case=end

// @lcpr case=start
// "abba"\n"dog cat cat fish"\n
// @lcpr case=end

// @lcpr case=start
// "aaaa"\n"dog cat cat dog"\n
// @lcpr case=end

 */

