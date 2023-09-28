//
// Created by miaohaochu on 2023/9/17.
//

#ifndef CPLUSPLUSTHINGS_EXCHANGE_H
#define CPLUSPLUSTHINGS_EXCHANGE_H
#include "iostream"
#include "vector"

using namespace std;
class Solution {
public:
    // The combination returns the number of coin combinations that can make up the total amount. If no coin combination can make up the total amount, return 0
    static int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1);
        sort(coins.begin(), coins.end());
        dp[0] = 1;
        if(amount == 0) return 0;
        // initialize
        for(auto &coin : coins) {
            if(coin <= amount) {
                dp[coin] = 1;
            }
        }

        for(int i = 1; i <= amount; i++ ) {
            if(dp[i] != 0 )continue;
            int min_last_status = INT_MAX, flag = 0;
            for(auto& coin : coins) {
                if((i - coin) > 0 && dp[i - coin] < min_last_status && dp[i - coin] != 0) {
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

#endif //CPLUSPLUSTHINGS_EXCHANGE_H

