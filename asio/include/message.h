//
// Created by miaohaochu on 2023/11/24.
//

#ifndef TALKING_ASYNC_MESSAGE_H
#define TALKING_ASYNC_MESSAGE_H

#include "deque"
#include "iostream"
#include "cstring"
#include <memory>
namespace net {


    template <class T>
    struct MessageHeader {
        size_t size{};
        T id{};
    };

    template <class T>
    struct Message {
        MessageHeader<T> header{};
        std::deque<uint8_t> body; //stream deque
        typedef Message<T> Self;
        [[nodiscard]] inline size_t size() const {
            return body.size() + sizeof(MessageHeader<T>);
        };
        T id() const {
            return header.id;
        };
        // display
        friend std::ostream& operator<<(std::ostream& os,const Message<T> & message) {
            std::cout<< " ID: " << int(message.id()) << " Size: " << message.header.size << std::endl;
            return os; // for chain call
        }
        // insert
        template<class DataType>
        friend Self& operator<<(Self& message,const DataType& data) {
            // place POD-Like data
            static_assert(std::is_standard_layout<DataType>::value, "too complex data type to push !!!"); //for serialize

            size_t origin_size = message.body.size();

            size_t need_add_size = sizeof(DataType);
            const auto* ptr = reinterpret_cast<const uint8_t*>(&data);

            size_t needSize = origin_size  + need_add_size;
            // increase mem
            message.body.resize(needSize);
            // fifo
            for(size_t i = 0; i < need_add_size; i++) {
                message.body[origin_size + i] = ptr[i];
            }
            message.header.size = message.body.size();
            return message;
        }

        // take out
        template<class DataType>
        friend Self& operator>>(Self& message, DataType& data) {
            // place POD-Like data
            static_assert(std::is_standard_layout<DataType>::value, "too complex data type to push !!!");

            size_t data_size = sizeof(DataType);

            if(message.body.size() < data_size) {
                throw std::runtime_error("not sufficient data");
            }

            auto* data_ptr = reinterpret_cast<uint8_t*>(&data);

            for(size_t i = 0; i < data_size; i++) {
                data_ptr[i] = message.body.front(); // reference
                message.body.pop_front();
            }

            message.header.size = message.body.size();
            return message;
        }
    };


    template <typename T>
    class Connection; // forward definition

    template <class T>
    struct OwnerMessage {
        std::shared_ptr<Connection<T>> remote = nullptr;
        Message<T> msg;

        friend std::ostream& operator<<(std::ostream& os,const  OwnerMessage<T>& message) {
            os << message;
            return os;
        }
    };
}


#endif //TALKING_ASYNC_MESSAGE_H
