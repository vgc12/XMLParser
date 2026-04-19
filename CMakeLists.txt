cmake_minimum_required(VERSION 4.3)
project(XMLParser)
set(CMAKE_CXX_STANDARD 20)

include_directories(/usr/include/libxml2)

add_executable(XMLParser main.cpp)
target_link_libraries(XMLParser xml2)