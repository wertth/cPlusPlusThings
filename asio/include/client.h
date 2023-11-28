//
// Created by miaohaochu on 2023/11/25.
//

#ifndef TALKING_ASYNC_CLIENT_H
#define TALKING_ASYNC_CLIENT_H
#include "asio.hpp"
#include "connection.h"
namespace net {
    template <typename T>
    class Client {
    public:
        Client() = default;
        virtual ~Client() {
            DisConnect();
        }

    public:
        bool Connect(const std::string& ip, uint16_t port);
        void DisConnect();
        [[nodiscard]] bool IsConnected() const {
            return m_connection && m_connection->isConnected();
        }
        void send(const Message<T>& message);

        ThreadSafeQueue<OwnerMessage<T>>& Incoming() {
            return m_message_in;
        }
    protected:
        // owned io context
        std::shared_ptr<asio::io_context> m_io_context;

        std::thread m_thread_context;

//        asio::ip::tcp::socket m_socket;

        ThreadSafeQueue<OwnerMessage<T>> m_message_in;

        std::unique_ptr<Connection<T>> m_connection;
    };

    template <typename T>
    bool Client<T>::Connect(const std::string& ip, const uint16_t port) {
        try {
            m_connection = std::make_unique<Connection<T>>(Connection<T>::Owner::CLIENT,
                                                           asio::ip::tcp::socket(*m_io_context),m_io_context, m_message_in);
            asio::ip::tcp::resolver resolver(*m_io_context);

            auto endpoints = resolver.resolve(ip, std::to_string(port));

            m_connection->connect(endpoints);

            m_thread_context = std::thread([this]() {
                (*m_io_context).run();
            });
            return true;
        } catch (std::exception& err){
            std::cerr << "[CLIENT] connect error: " << err.what() << std::endl;

            return false;
        }
    }

    template <typename T>
    void Client<T>::DisConnect(){
        if(m_connection && m_connection->isConnected()) {
            m_connection->disconnect();
        }
        (*m_io_context).stop();

        if(m_thread_context.joinable()) {
            m_thread_context.join();
        }
        m_connection.release();
    };

    template <typename T>
    void Client<T>::send(const Message<T>& message){
        if(m_connection && m_connection->isConnected()) {
            m_connection->send(message);
        } else {
            m_connection.release();
            std::cout<< "[CLIENT] send messagae " << std::endl;
        }

    }
}
#endif //TALKING_ASYNC_CLIENT_H
