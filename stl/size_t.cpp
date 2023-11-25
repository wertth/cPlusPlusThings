//
// Created by miaohaochu on 2023/11/9.
//
#include "iostream"
#include "format"
using namespace std;
// return the minimal
#define ALIGNS 8
size_t round_up(size_t bytes) {
    return (bytes + (size_t)ALIGNS - 1) & (~((size_t) ALIGNS - 1));
}

size_t floor_down(size_t bytes) {
    return (bytes) & (~(size_t)ALIGNS - 1);
}

template <typename T = size_t>
T round_up(T num, T multi) {
    if(multi == 0) return num;
    T remainder = num % multi;
    if(!remainder) return num;
    return num + multi - remainder;
}

template <typename T = size_t>
T floor_down(T num, T multi) {
    if(multi == 0) return num;
    T remainder = num % multi;
    if(!remainder) return num;
    return num  - remainder;
}


int main() {
    int a = (~((size_t) ALIGNS - 1));
    cout<< a << ' ' << bitset<sizeof(size_t) * 8>(a) << ' ' << &a << endl;
    cout<< sizeof( size_t ) << ' ' << sizeof (int) << endl;

    cout<< round_up(13) << ' ' << round_up(20) << ' '<< round_up(20,8)<< endl;
    return 0;
}