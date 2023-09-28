//
// Created by miaohaochu on 2023/9/16.
//

#ifndef CPLUSPLUSTHINGS_HEAP_H
#define CPLUSPLUSTHINGS_HEAP_H
#include "iostream"
template <typename DataType, typename Container = std::vector<DataType>,
        typename Compare = std::less<int> >
class Heap {
private:
    DataType const (* data);
    int _size{};
    int _capacity{};
public:
    Heap() = default;
    bool empty() {
        return _size == 0;
    }
    DataType top() {
        return (data)
    }
    void push(DataType & elem) {
        _size++;
    }
    void pop() {
        _size--;
    }

};
#endif //CPLUSPLUSTHINGS_HEAP_H
