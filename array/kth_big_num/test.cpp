//
// Created by miaohaochu on 2023/9/16.
//
#include "iostream"
#include "kth_big_num.h"
#include "../../utils/random_collection.h"
using namespace std;

int main() {
    vector<int> a = RandomCollectionUtil<vector<int> >::genRandomNumberCollection<int>(5, 10 ,25);
    for(auto &i: a) {
        cout<<i<< ' ';
    }
    cout<<endl;
    cout<< Solution::findKthLargest(a,3);
}