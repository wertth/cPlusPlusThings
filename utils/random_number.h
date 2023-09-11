//
// Created by miaohaochu on 2023/9/10.
//

#ifndef CPLUSPLUSTHINGS_RANDOM_NUMBER_H
#define CPLUSPLUSTHINGS_RANDOM_NUMBER_H
#include "iostream"
#include "random"
class RandomNumber {
public:
    template <typename T>
    static T genRandomNumber(T start, T end) {
        static_assert(std::is_arithmetic<T>::value, "T must be a specific arithmetic type");

//        T random = static_cast<T>(std::rand()) % static_cast<T> (RAND_MAX);

        return static_cast<T> (start + std::rand() % (end - start));
    }
};
#endif //CPLUSPLUSTHINGS_RANDOM_NUMBER_H
