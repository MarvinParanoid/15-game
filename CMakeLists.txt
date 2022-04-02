cmake_minimum_required(VERSION 3.21)
project(15)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

add_executable(15 main.cpp Game.cpp Game.h)

target_link_libraries(15 sfml-graphics)

add_custom_command(
        TARGET 15 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
        ${CMAKE_SOURCE_DIR}/OpenSans-Regular.ttf
        ${CMAKE_CURRENT_BINARY_DIR}/OpenSans-Regular.ttf)