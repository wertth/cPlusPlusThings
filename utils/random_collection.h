//
// Created by miaohaochu on 2023/9/10.
//

#ifndef CPLUSPLUSTHINGS_RANDOM_COLLECTION_H
#define CPLUSPLUSTHINGS_RANDOM_COLLECTION_H
#include "iostream"
#include "stdexcept"
#include "cstdlib"
#include "ctime"
#include "random_number.h"
// T: collection 类型
template <typename CollectionType>
class RandomCollectionUtil {
public:
    template<typename ContentType>
    static CollectionType genRandomNumberCollection(int size, int begin = 0, int end = 10) {
        try {
            CollectionType collection(size);
            srand(static_cast< unsigned >(std::time(nullptr)));
            // use iterator
            auto iter_begin = collection.begin(), iter_end = collection.end();
            while(iter_begin != iter_end) {
                *iter_begin = RandomNumber::genRandomNumber<ContentType>(begin, end);
                iter_begin++;
            }
            return collection;
        } catch (std::runtime_error &err) {
            std::cerr << err.what() << std::endl;
        }
    }
};



#endif //CPLUSPLUSTHINGS_RANDOM_COLLECTION_H
