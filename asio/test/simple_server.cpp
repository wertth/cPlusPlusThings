//
// Created by miaohaochu on 2023/11/27.
//

#include <iostream>
#include "simple_net.h"

enum class CustomMsgTypes : uint32_t
{
    ServerAccept,
    ServerDeny,
    ServerPing,
    MessageAll,
    ServerMessage,
};
class CustomServer : public net::Server<CustomMsgTypes> {
public:
    explicit CustomServer(uint16_t port) : net::Server<CustomMsgTypes>(port) {}
protected:
    bool OnClientConnect(std::shared_ptr<net::Connection<CustomMsgTypes>> connection) override{
        net::Message<CustomMsgTypes> msg;
        msg.header.id  = CustomMsgTypes::ServerAccept;
        connection->send(msg);
        return false;
    };

    void OnClientDisconnect(std::shared_ptr<net::Connection<CustomMsgTypes>> connection) override{
        std::cout << "Removing client [" << connection->id() << "]\n";
    };

    void OnMessage(std::shared_ptr<net::Connection<CustomMsgTypes>> connection,const net::Message<CustomMsgTypes>& message) override{
        switch (message.header.id)
        {
            case CustomMsgTypes::ServerPing:
            {
                std::cout << "[" << connection->id() << "]: Server Ping\n";

                // Simply bounce message back to client
                connection->send(message);
            }
                break;

            case CustomMsgTypes::MessageAll:
            {
                std::cout << "[" << connection->id() << "]: Message All\n";

                // Construct a new message and send it to all clients
                net::Message<CustomMsgTypes> msg;
                msg.header.id = CustomMsgTypes::ServerMessage;
                msg << connection->id();
                broadcast(msg);

            }
                break;
        }
    };

};

int main()
{
    CustomServer server(8090);
    server.start();

    while (true)
    {
        server.update(-1);
    }



    return 0;
}