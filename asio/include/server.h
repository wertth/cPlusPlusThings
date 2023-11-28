//
// Created by miaohaochu on 2023/11/25.
//

#ifndef TALKING_ASYNC_SERVER_H
#define TALKING_ASYNC_SERVER_H
#include <cstdint>
#include "asio.hpp"
#include "connection.h"
#include "memory"
#include <vector>
#include "thread_safe_queue.h"
#include <deque>
namespace net {
    template <typename T>
    class Server {
    public:
        typedef std::vector<std::shared_ptr<Connection<T>>> IgnoreConnections;
        typedef std::deque<std::shared_ptr<Connection<T>>> Connections;
        explicit Server(uint16_t port)
        :m_acceptor(*m_asio_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(),port)) {
            ///
        }
        virtual ~Server() {
            stop();
        }

        bool start(){
            try{
                WaitForClientConnection();
                m_thread = std::thread([&](){m_asio_context->run();});
            } catch (std::exception& err) {
                std::cerr<< "[SERVER] exception: " << err.what() << std::endl;
                return false;
            }
            std::cout<< "[SERVER] started" << std::endl;
            return true;
        };

        bool stop() {
            m_asio_context->stop();
            if(m_thread.joinable()) m_thread.join();

            std::cout<< "[SERVER] stopped!!" << std::endl;
            return true;
        };

        bool sendMessage(std::shared_ptr<Connection<T>> connection,const Message<T>& message);

        void broadcast(const Message<T> & message,const IgnoreConnections& ignoreConnections = IgnoreConnections());

        void WaitForClientConnection();

        void update(size_t nMaxMessageNum = -1) {
//            if(wait) m_message_in.wait();
            size_t nMessageNum = 0;
            while(nMessageNum < nMaxMessageNum && !m_message_in.empty()) {
                auto msg = m_message_in.pop_front();
                OnMessage(msg.remote, msg.msg);
                nMessageNum++;
            }
        }

    protected:
        virtual bool OnClientConnect(std::shared_ptr<Connection<T>> connection){
            return false;
        }

        virtual void OnClientDisconnect(std::shared_ptr<Connection<T>> connection){};

        virtual void OnMessage(std::shared_ptr<Connection<T>> connection,const Message<T>& message){};

        ThreadSafeQueue<OwnerMessage<T>> m_message_in;

        std::shared_ptr<asio::io_context> m_asio_context;

        std::thread m_thread;

        asio::ip::tcp::acceptor m_acceptor;

        uint32_t m_nIDCounter = 10000;

        Connections connections;

    };

    template <typename T>
    void Server<T>::WaitForClientConnection (){
        m_acceptor.async_accept([this](std::error_code ec, asio::ip::tcp::socket socket) {
            if(!ec){
                std::cout<< "[SERVER] new connection:" << socket.remote_endpoint() << std::endl;

                // make new conn
                std::shared_ptr<Connection<T>> connection = std::make_shared<Connection<T>>(
                        Connection<T>::Owner::SERVER,
                        std::move(socket),
                        m_asio_context,
                        m_message_in
                        );

                if(OnClientConnect(connection)) {
                    connections.push_back(std::move(connection));
                    (*connections.back()).connect(m_nIDCounter++);
                    std::cout<< "[SERVER] connection " << connections.back()->id() << " approved " << std::endl;
                }
            } else {
                std::cerr<< "[SERVER] new connection err:" << ec.message() << std::endl;
            }
            WaitForClientConnection(); // keep waiting
        });

    }

    template <typename T>
    bool Server<T>::sendMessage(std::shared_ptr<Connection<T>> connection,const Message<T>& message) {
        if(connection && connection->isConnected()) {
            connection->send(message);
            std::cout<< "[SERVER] send message" << message << std::endl;
            return true;
        } else {
            OnClientDisconnect(connection);
            connection.reset();
            std::cout<< "[SERVER] send message err!!!" <<  std::endl;
            connections.erase(std::find(connections.begin(), connections.end(), connection));
            return false;
        }

    }


    template <typename T>
    void Server<T>::broadcast(const Message<T> &message, const IgnoreConnections& ignoreConnections) {
        std::for_each(connections.begin(), connections.end(), [&](const auto& conn) {
            if (ignoreConnections.empty() || std::find(ignoreConnections.begin(), ignoreConnections.end(), conn) == ignoreConnections.end()) {
                this->sendMessage(conn, message);
            }
        });
    }


}

#endif //TALKING_ASYNC_SERVER_H
