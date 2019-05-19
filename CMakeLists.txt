cmake_minimum_required(VERSION 3.14)
project(card_karuba_environment)

set(CMAKE_CXX_STANDARD 14)

add_executable(card_karuba_environment
        main.cpp)

include_directories(card_karuba_lib)

add_subdirectory(card_karuba_lib)
add_subdirectory(card_karuba_tests)
