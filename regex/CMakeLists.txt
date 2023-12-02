cmake_minimum_required(VERSION 3.22)
project(regex)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(regex main.cpp)

set(Boost_USE_STATIC_LIBS OFF)

# 指定Boost库的根目录。替换为你的Boost库的路径。
set(BOOST_ROOT "/usr/local/")

# 这个指令让CMake寻找你指定的Boost组件。在这个例子中，它寻找system和filesystem库。
# 如果你需要其他的Boost库，你可以在此处列出它们。
find_package(Boost REQUIRED COMPONENTS system filesystem)

#add_executable(cPlusPlusThings main.cpp)

# 这些指令将Boost的头文件目录和库添加到你的项目。
include_directories(${Boost_INCLUDE_DIRS})