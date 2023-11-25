//
// Created by miaohaochu on 2023/10/19.
//
#include "iostream"
#include "sstream"
#include "unordered_map"
#include "fstream"
#include "string"
#include "vector"
#include "algorithm"
#include <unistd.h>
// input file : input.txt
// mapper
// pair<string, int>
typedef std::pair<std::string,int> CountPair;
typedef std::vector<CountPair> CountPairList;

void Mapper (const std::string &line, CountPairList & count_pair_list) {
    std::istringstream iss(line);
    std::string word;
    while(iss >> word) {
        count_pair_list.emplace_back(word, 1);
    }
}


typedef std::unordered_map<std::string, std::vector<int>> ShuffleOutput;
void Shuffle(const CountPairList& list, ShuffleOutput & output) {
    for(const auto &kv : list) {
        output[kv.first].push_back(kv.second);
    }
}
typedef std::unordered_map<std::string , int > ReduceOutput;
void Reducer(const ShuffleOutput& shuffleOutput, ReduceOutput & reducerOutput) {
    for(const auto & item: shuffleOutput) {
        int sum = 0 ;
        for(auto val : item.second) {
            sum+=val;
        }
        reducerOutput[item.first] = sum;
    }
}


int main() {
    // Read input data
    std::ifstream infile("./input.txt");
    if(!infile) {
        std::cout<< "no file" << std::endl;
        return -1;
    }
    std::string line;
    CountPairList mapperOutput;
    while (std::getline(infile, line)) {
        Mapper(line, mapperOutput);
    }

    // Shuffle
    ShuffleOutput shuffleOutput;
    Shuffle(mapperOutput, shuffleOutput);

    // Reduce
    ReduceOutput reduceOutput;
    Reducer(shuffleOutput, reduceOutput);

    // Output result
    for (const auto& item : reduceOutput) {
        std::cout << item.first << ": " << item.second << std::endl;
    }




    return 0;
}
