//
// Created by miaohaochu on 2023/9/9.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "merge_two_sorted.h"
#include "merge_two_sorted_test_sample.h"
using namespace std;
int main () {

    int m = 3, n = 10;
    vector<int> v1 = Sample::genRandomNums(m+n, 0, 100, m);

    vector<int> v2 = Sample::genRandomNums(n, 0 ,100);

    sort(v1.begin(), v1.begin() + m, less<int>());
    sort(v2.begin(), v2.end(), less<int>());

    cout << "***" << endl;
    Solution::display(v1);
    cout<< "___" << endl;
    Solution::display(v2);
    cout << "***" << endl;
    Solution::merge(v1, m , v2, n);
    cout << "***" << endl;
    Solution::display(v1);

    return 0;


}
