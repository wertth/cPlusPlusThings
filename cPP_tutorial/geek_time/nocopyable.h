//
// Created by miaohaochu on 2023/10/26.
//

#ifndef CPLUSPLUSTHINGS_NOCOPYABLE_H
#define CPLUSPLUSTHINGS_NOCOPYABLE_H
namespace muduoExp {
    class nocopyable {
    public:
        nocopyable(nocopyable & temp) = delete;
        void operator=(nocopyable & temp) = delete;
    protected:
        nocopyable() = default;
        ~nocopyable() = default;
    };
}
#endif //CPLUSPLUSTHINGS_NOCOPYABLE_H
