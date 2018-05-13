project(hexTests)
add_subdirectory(googletest/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(runTests hexTests.cpp)
target_link_libraries(runTests gtest gtest_main)
target_link_libraries(runTests hex)