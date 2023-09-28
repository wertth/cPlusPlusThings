//
// Created by miaohaochu on 2023/9/26.
//

#ifndef CPLUSPLUSTHINGS_RANDOMIZEDSET_H
#define CPLUSPLUSTHINGS_RANDOMIZEDSET_H
#include "iostream"
#include "vector"
#include "map"
#include "unordered_map"
class RandomizedSet {
private:
    std::unordered_map<int,int> _map;
public:
    RandomizedSet() {
        srand((unsigned )time(0));
    }

    bool insert(int val) {
        if(_map.contains(val)) return false;
        else {
            _map.insert(std::pair<int,int>(val,0));
            return true;
        }
    }

    bool remove(int val) {
       return _map.erase(val);
    }

    int getRandom() {
//        srand((unsigned )time(0));
        int rand = random() % _map.size();
        int size = _map.size();
        auto begin = _map.begin();
        if(size == 1) return begin -> first;
        for(int i = 0 ; i< rand ; i++ ) {
            begin++;
        }
        return size > 1 ? (begin) ->first  : 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
#endif //CPLUSPLUSTHINGS_RANDOMIZEDSET_H
