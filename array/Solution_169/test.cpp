//
// Created by miaohaochu on 2023/9/14.
//
#include "majority_num.h"
#include "../../utils/random_collection.h"
#include "iostream"
#include "vector"
using namespace std;

int main() {
    vector<int> vec = RandomCollectionUtil<vector<int> >::genRandomNumberCollection<int>(10,0,2);
    for (auto i: vec) {
        cout<< i << ' ';
    }
    int major = Solution::majorityElement(vec);
    cout<<endl;
    cout << major;
}
