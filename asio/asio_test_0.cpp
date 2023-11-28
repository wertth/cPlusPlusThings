//
// Created by miaohaochu on 2023/11/23.
//

#include "asio.hpp"
#include <iostream>
#include <vector>
#include <memory>

using asio::ip::tcp;
// 「note: 异步递归 实际目的为下次操作排队, 并不会出现递归站太深的问题」
void GrabData(tcp::socket& socket, std::shared_ptr<std::vector<char>> cBuffer) {
    socket.async_read_some(asio::buffer(*cBuffer),
                           [cBuffer,&socket](const std::error_code& errorCode, std::size_t length) {
                               if (!errorCode) {
                                   std::cout << "\n\nRead " << length << " bytes" << std::endl;
                                   for (std::size_t i = 0; i < length; ++i) {
                                       std::cout << (*cBuffer)[i];
                                   }
                                   std::cout << std::endl;
                                   GrabData(socket,cBuffer); // Recursive call to read more data
                               } else {
                                   std::cerr << "Error: " << errorCode.message() << std::endl;
                               }
                           });
}

int main() {
    asio::io_context context;
    std::error_code errorCode;
    tcp::endpoint endpoint(asio::ip::make_address("192.168.1.13", errorCode), 8090);

    tcp::socket sock(context);

    sock.connect(endpoint, errorCode);

    if (errorCode) {
        std::cerr << "Connection failed: " << errorCode.message() << std::endl;
        return 1;
    } else {
        std::cout << "Connection succeeded" << std::endl;
    }

    std::string sRequest = "GET /index.html HTTP/1.1\r\n"
                           "Host: 192.168.1.13\r\n"
                           "Connection: close\r\n\r\n"; // Adding Host header and closing connection after response

    asio::write(sock, asio::buffer(sRequest), errorCode);

    if (errorCode) {
        std::cerr << "Write failed: " << errorCode.message() << std::endl;
        return 1;
    }
    auto cBuffer = std::make_shared<std::vector<char>>(10*1024);
    GrabData(sock,cBuffer);
    context.run(); // This will run the async_read_some until it completes or fails

    return 0;
}
