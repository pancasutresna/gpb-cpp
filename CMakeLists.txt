cmake_minimum_required(VERSION 3.14)
project(Blockchain)

set(CMAKE_CXX_STANDARD 14)

include_directories(Blockchain)

add_executable(Blockchain
        src/Block.cpp
        src/Block.h
        src/Blockchain.cpp
        src/Blockchain.h
        src/main.cpp
        src/crypto/picosha2.h src/type/uint256.h)
