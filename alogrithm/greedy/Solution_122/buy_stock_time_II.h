//
// Created by miaohaochu on 2023/9/22.
//

#ifndef CPLUSPLUSTHINGS_BUY_STOCK_TIME_II_H
#define CPLUSPLUSTHINGS_BUY_STOCK_TIME_II_H
#include "iostream"
#include "vector"

using namespace std;
class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        if(prices.size() == 1 || prices.size() == 0) return 0;
        int len = prices.size();
        int left = 0 , right = 0, profit = 0;
        while( left < len - 1 && right < len - 1 ) {
            if(prices[left+1] < prices[left]) left++;
            else {
                right = left;
                while(right < len - 1 && prices[right+1] > prices[right])right++;

                profit += prices[right] - prices[left];
                left = right+ 1;

            }
        }
        return profit;
    }
};
#endif //CPLUSPLUSTHINGS_BUY_STOCK_TIME_II_H
