//
// Created by miaohaochu on 2023/9/27.
//

#ifndef CPLUSPLUSTHINGS_GASSTATION_H
#define CPLUSPLUSTHINGS_GASSTATION_H
#include "iostream"
#include "vector"

using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        return Solution::canContinueJourney(gas,cost,0,0,0);
    }
    static int canContinueJourney(vector<int>& gas, vector<int>& cost,int begin,int position, int remainGas){
        int gainGas = gas[position], needCost = cost[position];
        int size = gas.size(), remain = gainGas + remainGas - needCost;
        if(size == 1) {
            return remain >= 0 ? begin : -1;
        }
        if(position == begin) {
            for(int i= 0; i < size; i++){
               remain = gas[i] - cost[i];
               int temp = -1;
               if(remain > 0) {
                   temp = canContinueJourney(gas,cost,i,(i + 1) % size, remain);
               }
               if(temp >=0) return temp;
            }
        } else {
            if((position + 1 )% size == begin && remain>=0) return begin;
            if(remain < 0) return -1;
            return canContinueJourney(gas,cost,begin,(position+1)%size, remain);
        }
        return -1;

    }
};
#endif //CPLUSPLUSTHINGS_GASSTATION_H
