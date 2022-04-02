cmake_minimum_required(VERSION 3.21)
project(15)
set(CMAKE_CXX_STANDARD 17)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

file(GLOB SOURCES "src/*.cpp")
add_executable(15 ${SOURCES})

target_link_libraries(15 sfml-graphics)

add_custom_command(
        TARGET 15 POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources/
        ${CMAKE_CURRENT_BINARY_DIR}/resources/)