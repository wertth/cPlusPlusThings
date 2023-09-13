//
// Created by miaohaochu on 2023/9/11.
//
#include "iostream"
#include "algorithm"
#include "../../utils/random_collection.h"
#include "remove_duplicate_sorted_with_n_times.h"
using namespace std;

int main() {
    vector<int> a = RandomCollectionUtil<vector<int> >::genRandomNumberCollection<int>(10, 0,5);
    sort(a.begin(), a.end(), less<int>());
    cout<< "before remove:" << endl;
    for (auto &i : a) {
        cout<< i << ' ';
    }
    cout<<endl;
    cout<< "after remove:" << endl;
    int new_len = Solution::removeExtraDuplicateWithNTimes(a,2);
    for (int i = 0; i < new_len; i++) {
        cout<< a[i] << ' ';
    }
}
