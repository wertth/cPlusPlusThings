//
// Created by miaohaochu on 2023/9/10.
//

#include "remove_element_in_place.h"
#include "iostream"
#include "vector"
#include "../../utils/random_collection.h"
using namespace std;

int main () {
    vector<int> a =  RandomCollectionUtil <vector<int> >::genRandomNumberCollection<int>(20);
    cout<< "before remove: " << endl;
    for(auto &i : a) {
        cout<< i << ' ';
    }
    cout<< endl;
    Solution::removeElement(a, 1);
    cout<< "after remove: " << endl;
    for(auto &i : a) {
        cout<< i << ' ';
    }
}
