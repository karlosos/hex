cmake_minimum_required(VERSION 3.7.2)
project(hex)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp)
add_executable(runHex ${SOURCE_FILES})
add_subdirectory(tests)
add_subdirectory(src)
target_link_libraries(runHex hex)