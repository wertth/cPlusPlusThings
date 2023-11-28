//
// Created by miaohaochu on 2023/11/25.
//

#ifndef TALKING_ASYNC_CONNECTION_H
#define TALKING_ASYNC_CONNECTION_H
#include <memory>
#include <utility>
#include "message.h"
#include "asio.hpp"
#include "thread_safe_queue.h"
namespace net {
    template <typename T>
    class Connection: public std::enable_shared_from_this<Connection<T>> {
    public:
        enum Owner {
            SERVER,
            CLIENT
        };
        Connection() = delete;
        Connection(Owner owner,asio::ip::tcp::socket socket,std::shared_ptr<asio::io_context> io_cntext,
                   ThreadSafeQueue<OwnerMessage<T>> &message_in)
                :m_owner(owner), m_socket(std::move(socket)),m_message_in(message_in),m_io_cntext(io_cntext){};
        virtual ~Connection(){
            disconnect();
        }

    public:
        // for server to client
        bool connect(uint64_t uid);
        // for client to server
        bool connect(const asio::ip::tcp::resolver::results_type& endpoints);
        bool disconnect();
        [[nodiscard]] bool isConnected() const {
            return m_socket.is_open();
        };
        void send(const Message<T>& message);

        [[nodiscard]] uint64_t id() const {
            return m_id;
        }

        // for derive
    protected:
        Owner m_owner;

        asio::ip::tcp::socket m_socket;

        std::shared_ptr<asio::io_context> m_io_cntext;

        ThreadSafeQueue<Message<T>> m_message_out;

        ThreadSafeQueue<OwnerMessage<T>>& m_message_in;

        uint64_t m_id = 0;

        Message<T> m_temporary_message_in;

    private:
        // pre read the header info from the Message<T>
        void ReadHeader() {
            asio::async_read(m_socket,asio::buffer(&m_temporary_message_in.header,sizeof(MessageHeader<T>)),
                 [this](std::error_code ec,std::size_t len){
                    if(!ec) {
                        if(m_temporary_message_in.header.size > 0) {
                            m_temporary_message_in.body.resize(m_temporary_message_in.header.size);
                            ReadBody();
                        } else {
                            AddIncomingMessageQueue();
                        }
                    } else {
                        std::cout<< "[CONNECTION] read header failed" << std::endl;
                        m_socket.close();
                    }

            });
        }


        void ReadBody() {
            asio::async_read(m_socket,asio::buffer(&m_temporary_message_in.body[0],
                 m_temporary_message_in.body.size()),
                 [this](std::error_code ec, std::size_t len){
                    if(!ec) {
                        AddIncomingMessageQueue();
                    } else {
                        std::cout<< "[CONNECTION] read body failed" << std::endl;
                        m_socket.close();
                    }
            });
        }

        void AddIncomingMessageQueue() {
            if(m_owner == Owner::SERVER) {
                m_message_in.push_back({
                    this->shared_from_this(),
                    m_temporary_message_in
                });

            } else {
                m_message_in.push_back({
                        nullptr,
                        m_temporary_message_in
                });
            }
            ReadHeader();
        }

        void WriteHeader() { // ??
            asio::async_write(m_socket,asio::buffer(&m_message_out.front().header, sizeof(MessageHeader<T>)),
                 [this](std::error_code ec, std::size_t len){
                    if(!ec) {
                        if(m_message_out.front().body.size() > 0) {
                            WriteBody();
                        } else {
                            m_message_out.pop_front();

                            if(!m_message_out.empty()) {
                                WriteHeader();
                            }
                        }
                    } else {
                        m_socket.close();
                    }
            });
        }

        void WriteBody() {
            asio::async_write(m_socket,
                 asio::buffer(&m_message_out.front().body[0], m_message_out.front().body.size()),
                 [this](std::error_code ec, std::size_t len){
                       if(!ec) {
                           m_message_out.pop_front();
                           if(!m_message_out.empty()) {
                               WriteHeader();
                           }

                       } else {
                           m_socket.close();
                       }
            });
        }

    };


    template <typename T>
    bool Connection<T>::connect(uint64_t uid){
        try {
            if (m_owner == Owner::SERVER)  // -> client
            {
                if (isConnected()) {
                    m_id = uid;
                    ReadHeader();
                }
            }
            return true;
        } catch (std::exception& err) {
            //
            return false;
        }
    }

    template <typename T>
    bool Connection<T>::connect(const asio::ip::tcp::resolver::results_type& endpoints) {
        try {
            if(m_owner == Owner::CLIENT) {
                asio::async_connect(m_socket, endpoints, [this] (std::error_code ec, asio::ip::tcp::endpoint endpoint) {
                    if(!ec) {
                        ReadHeader();
                    }
                });
            }
            return true;
        } catch (std::exception& err) {
            std::cerr << "[CONNECTION] err" << err.what() << std::endl;
            return false;
        }
    }


    template <typename T>
    bool Connection<T>::disconnect() {
        if(isConnected()) {
            asio::post(*m_io_cntext, [this]() {
                m_socket.close();
            });
        }
        return true;
    }

    template <typename T>
    void Connection<T>::send(const Message<T>& message){
        asio::post(*m_io_cntext,[this,message]() {
           m_message_out.push_back(message);
           if(m_message_out.empty()) WriteHeader();
        });
    }
}
#endif //TALKING_ASYNC_CONNECTION_H
