#include <string>
#include <vector>
#include <unordered_map>

#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<int, vector<char>> map = {
            {2,{'a','b','c'}},
            {3,{'d','e','f'}},
            {4,{'g','h','i'}},
            {5,{'j','k','l'}},
            {6,{'m','n','o'}},
            {7,{'p','q','r','s'}},
            {8,{'t','u','v'}},
            {9,{'w','x','y','z'}}
        };
        vector<string> res = {""};

        for(int i = 0; i < digits.size(); i++) {
            int num = digits[i] - '0';
            vector<char> alternative = map[num];
            selectRecursive(res, alternative, 0);
        }
        return res;

    }

    static void selectRecursive(vector<string>& res,vector<char>& alternative, int index) {
        vector<string> temp;
        if(index == res.size()) {
            return;
        }
        for(int i = 0; i < alternative.size(); i++) {
            temp.push_back(res[index] + alternative[i]);
        }
        res.erase(res.begin() + index);
        res.insert(res.begin() + index, temp.begin(), temp.end());
        selectRecursive(res, alternative, index + temp.size());

    }

};

int main() {
    Solution s;
    vector<string> res = s.letterCombinations("23");
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
    return 0;
}