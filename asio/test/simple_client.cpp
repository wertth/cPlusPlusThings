//
// Created by miaohaochu on 2023/11/27.
//
#include "simple_net.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <termios.h>
#include <unistd.h>

enum class CustomMsgTypes : uint64_t  {
    ServerAccept,
    ServerDeny,
    ServerPing,
    MessageAll,
    ServerMessage,
};

class CustomClient: public net::Client<CustomMsgTypes> {
public:
    void PingServer() {
        net::Message<CustomMsgTypes> msg;
        msg.header.id = CustomMsgTypes::ServerPing;

        std::chrono::system_clock::time_point  timeNow = std::chrono::system_clock::now();


        msg << timeNow;
        send(msg);
    }

    void MessageAll() {
        net::Message<CustomMsgTypes> msg;
        msg.header.id = CustomMsgTypes::MessageAll;
        send(msg);
    }
};
void SetTerminalMode(bool enable) {
    static struct termios oldt, newt;
    if (enable) {
        tcgetattr(STDIN_FILENO, &oldt); // 获取终端属性
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO); // 设置非标准模式和关闭回显
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // 应用新属性
    } else {
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // 恢复终端属性
    }
}

// 函数用于检查键盘是否有按键按下
bool IsKeyPressed(char key) {
    int ch;
    struct timeval tv{};
    fd_set rdfs;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    FD_ZERO(&rdfs);
    FD_SET(STDIN_FILENO, &rdfs);

    select(STDIN_FILENO + 1, &rdfs, nullptr, nullptr, &tv);

    if (FD_ISSET(STDIN_FILENO, &rdfs)) {
        ch = getchar();
        return ch == key;
    }
    return false;
}

int main() {
    // 设置终端为非阻塞读取模式
    SetTerminalMode(true);

    CustomClient c;
    c.Connect("127.0.0.1", 60000);

    bool key[3] = { false, false, false };
    bool old_key[3] = { false, false, false };

    bool bQuit = false;
    while (!bQuit) {
        key[0] = IsKeyPressed('1');
        key[1] = IsKeyPressed('2');
        key[2] = IsKeyPressed('3');

        if (key[0] && !old_key[0]) c.PingServer();
        if (key[1] && !old_key[1]) c.MessageAll();
        if (key[2] && !old_key[2]) bQuit = true;

        for (int i = 0; i < 3; i++) old_key[i] = key[i];

        // ... 其余的代码与你的 Windows 版本相同 ...

        // 给服务器处理消息的时间
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }

    // 在退出前恢复终端设置
    SetTerminalMode(false);

    return 0;
}