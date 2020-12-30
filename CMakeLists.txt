cmake_minimum_required(VERSION 3.17)
project(zadacha1)

set(CMAKE_CXX_STANDARD 17)

include_directories()

set(
        GRP
        ArcGraph.cpp
        ListGraph.cpp
        MatrixGraph.cpp
        SetGraph.cpp
)

add_executable(zadacha1 main.cpp ${GRP})