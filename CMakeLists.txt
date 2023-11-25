cmake_minimum_required(VERSION 3.25.2)
project(cPlusPlusThings)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#set(CMAKE_CXX_FLAGS "-O3 -Wall -Wextra")

# 下面的指令告诉CMake你想要动态链接Boost库。如果你想要静态链接，你可以将其设置为ON。
set(Boost_USE_STATIC_LIBS OFF)

# 指定Boost库的根目录。替换为你的Boost库的路径。
set(BOOST_ROOT "/usr/local/")

# 这个指令让CMake寻找你指定的Boost组件。在这个例子中，它寻找system和filesystem库。
# 如果你需要其他的Boost库，你可以在此处列出它们。
find_package(Boost REQUIRED COMPONENTS system filesystem)

add_executable(cPlusPlusThings stl/size_t.cpp)

# 这些指令将Boost的头文件目录和库添加到你的项目。
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(cPlusPlusThings ${Boost_LIBRARIES})
