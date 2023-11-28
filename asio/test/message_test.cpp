//
// Created by miaohaochu on 2023/11/24.
//

#ifndef TALKING_ASYNC_MESSAGE_TEST_CPP
#define TALKING_ASYNC_MESSAGE_TEST_CPP

// ...
#include <message.h>
#include <cassert>
#include <iostream>
#include <string>

enum CustomDataTypes : uint32_t {
    MOVE_PLAYER,
    FIRE_BULLET
};

struct MyStruct {
    int c = 9;
    char d = 'y';
}; // struct member byte fill

int main () {
    net::Message<CustomDataTypes> message;
    message.header.id = CustomDataTypes::MOVE_PLAYER;

    int a = 1;
    float b = 4.23441f;
    MyStruct g;


    message << a << b << g;

    std::cout << message << std::endl;
    size_t expect_size = sizeof(a) + sizeof(b) + sizeof(g.c) + sizeof(g.d)+ (std::abs((int)(sizeof(g.c) - sizeof(g.d))));
    assert(expect_size == message.size());

    int deserialized_a;
    float deserialized_b;
    MyStruct deserialized_g;
    message >> deserialized_a >> deserialized_b >> deserialized_g;

    assert(deserialized_a == a );
    assert(deserialized_b == b);
    assert(deserialized_g.d == g.d && deserialized_g.c == g.c);
    assert(message.body.size() == 0);





    return 0;
}

#endif //TALKING_ASYNC_MESSAGE_TEST_CPP
