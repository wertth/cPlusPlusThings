//
// Created by miaohaochu on 2023/9/11.
//
#include "iostream"
#include "../../utils/random_collection.h"
#include "vector"
#include "remove_duplicate_sorted.h"
#include "algorithm"
using namespace std;

int main() {
    vector<int> a = RandomCollectionUtil<vector<int> >::genRandomNumberCollection<int>(20, 60 , 100);
    sort(a.begin(), a.end(), less<int>());
    cout<< "before remove:" << endl;
    for (auto &i : a) {
        cout<< i << ' ';
    }
    cout<<endl;
    cout<< "after remove:" << endl;
    int new_len = Solution::removeDuplicates(a);
    for (int i = 0; i < new_len; i++) {
        cout<< a[i] << ' ';
    }
}
