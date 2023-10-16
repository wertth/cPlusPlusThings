//
// Created by miaohaochu on 2023/10/17.
//
#include "word_count_frequency.hpp"
#include "iostream"
#include "cassert"
using namespace std;
void testGetWordsFrequency() {
    std::string input = "hello world hello hello world universe";
    sortedArray output = getWordsFrequency(input);
    assert(output[0].first == 3 && output[0].second == "hello");
    assert(output[1].first == 2 && output[1].second == "world");
    assert(output[2].first == 1 && output[2].second== "universe");
    std::cout << "All tests passed!" << std::endl;
}

int main() {
    testGetWordsFrequency();
    return 0;
}

