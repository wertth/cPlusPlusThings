//
// Created by miaohaochu on 2023/10/16.
//
#include "iostream"
#include "unordered_map"
#include "vector"
#include "algorithm"
//input --> long str

// output -> sorted array with frequency
typedef std::unordered_map<std::string, int> wordCountMap;
typedef std::vector<std::pair<int, std::string>> sortedArray;

struct Greater {
    bool operator () (std::pair<int, std::string> & lhs,
                      std::pair<int, std::string> & rhs) const {
        return lhs.first > rhs.first;
    }
};
sortedArray getWordsFrequency(std::string & str) {
    sortedArray arr;
    auto wordsSplitFunc = [](std::string & str, char split) -> std::vector<std::string> {
        std::vector<std::string> res;
        std::string tmp;
        for(char elem: str) {
            if(elem == split) {
                res.push_back(tmp);
                tmp.clear();
            } else {
                tmp.push_back(elem);
            }
        }
        if(!tmp.empty()) res.push_back(tmp);
        return res;
    };
    std::vector<std::string> sepWordList = wordsSplitFunc(str, ' ');



    wordCountMap wordCount;
    for(auto & elem : sepWordList) {
        wordCount[elem]++;
    } // save to the hashMap

    // sort
    auto begin = wordCount.begin(), end = wordCount.end();
    for(auto it = begin; it != end; it++ ) {
        arr.push_back(std::make_pair(it->second,it->first));
    }

    std::sort(arr.begin(), arr.end(), Greater());

    return arr;
}


