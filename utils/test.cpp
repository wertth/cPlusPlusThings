//
// Created by miaohaochu on 2023/9/10.
//
#include "random_collection.h"
#include "iostream"
#include "vector"
#include "list"
#include "deque"
#include "string"
#include "forward_list"
using namespace std;
int main() {

    vector<int> a =  RandomCollectionUtil<vector<int> >::genRandomNumberCollection<int>(10);
    deque<long> b = RandomCollectionUtil<deque<long> >::genRandomNumberCollection<long>(20);
    list<int> c = RandomCollectionUtil<list<int> >::genRandomNumberCollection<int>(100);
    forward_list<unsigned > d = RandomCollectionUtil<forward_list<unsigned > >::genRandomNumberCollection<unsigned >(100);
    for (auto &i : a) {
        cout<< i << endl;
    }
//    for(auto i: b) {
//        cout<< i << endl;
//    }
}