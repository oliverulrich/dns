cmake_minimum_required(VERSION 3.20)

project(dns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(dns
        src/main.cpp
        src/Logger.cpp
        src/Logger.h
        src/Blocklist.cpp
        src/Blocklist.h
        src/BlocklistLoader.cpp
        src/BlocklistLoader.h
)

target_compile_options(dns PRIVATE -Wall -Wextra -Wpedantic -Werror)
