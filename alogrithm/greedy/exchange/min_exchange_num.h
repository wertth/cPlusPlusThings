//
// Created by miaohaochu on 2023/9/17.
//

#ifndef CPLUSPLUSTHINGS_MIN_EXCHANGE_NUM_H
#define CPLUSPLUSTHINGS_MIN_EXCHANGE_NUM_H
#include "iostream"
#include "vector"

using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        sort(coins.begin(), coins.end());
        dp[0] = 0;
        if(amount == 0) return 0;
        // initialize
        for(auto &coin : coins) {
            dp[coin] = 1;
        }

        for(int i = 1; i <= amount; i++ ) {
            if(dp[i] != 0 )continue;
            int min_last_status = INT_MAX, flag = 0;
            for(auto& coin : coins) {
                if((i - coin) > 0 && dp[i - coin] < min_last_status) {
                    min_last_status = dp[i-coin];
                    flag = 1;
                }
            }
            if(flag == 1) {
                dp[i] = min_last_status + 1;
            } else if( i == amount) {
                return -1;
            }
        }

        return dp[amount];
    }
};
#endif //CPLUSPLUSTHINGS_MIN_EXCHANGE_NUM_H
