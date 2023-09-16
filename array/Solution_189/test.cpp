//
// Created by miaohaochu on 2023/9/16.
//
#include "../../utils/random_collection.h"
#include "iostream"
#include "rotate_array.h"
using namespace std;

int main() {
    vector<int> a = RandomCollectionUtil<vector<int> >::genRandomNumberCollection<int>( 5 , 0 ,5);
    Solution::rotate(a,3);
    vector<vector<int> > vec {{1,2,3},{1,2,3}};
}
