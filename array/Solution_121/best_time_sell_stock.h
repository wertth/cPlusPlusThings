//
// Created by miaohaochu on 2023/9/17.
//

#ifndef CPLUSPLUSTHINGS_BEST_TIME_SELL_STOCK_H
#define CPLUSPLUSTHINGS_BEST_TIME_SELL_STOCK_H
#include "iostream"
#include "vector"
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost = INT_MAX, profit = 0;
        for(int &price : prices) {
            cost = min(cost, price);
            profit = max(price - cost, profit);
        }
        return profit;
    }
};
#endif //CPLUSPLUSTHINGS_BEST_TIME_SELL_STOCK_H
