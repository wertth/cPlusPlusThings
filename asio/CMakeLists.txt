cmake_minimum_required(VERSION 3.22)
#set(ASIO_DIR "")
set(CMAKE_CXX_STANDARD 20)
project(talking_async)

include_directories(/usr/asio/asio-1.28.0/include)
include_directories(./include)

add_executable(client
        test/simple_client.cpp)
add_executable(server
        test/simple_server.cpp)

target_compile_definitions(client PRIVATE ASIO_STANDALONE)
target_compile_definitions(server PRIVATE ASIO_STANDALONE)
target_link_libraries(client pthread)
target_link_libraries(server pthread)


#add_custom_command(TARGET client POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E chmod u+x $<TARGET_FILE:client>)
#add_custom_command(TARGET server POST_BUILD
#        COMMAND ${CMAKE_COMMAND} -E chmod u+x $<TARGET_FILE:server>)


