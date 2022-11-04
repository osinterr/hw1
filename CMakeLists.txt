cmake_minimum_required(VERSION 3.5)

project(cmake_hw1)

set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")

add_executable(App
               main.cpp
               src/Vector.cpp
               src/Matrix.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

add_executable(
    tests
    tests.cpp
    src/Vector.cpp
    src/Matrix.cpp
)
target_link_libraries(
    tests
    gtest 
    pthread
)

enable_testing()


include(GoogleTest)
gtest_discover_tests(tests)