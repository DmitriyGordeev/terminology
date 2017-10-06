cmake_minimum_required(VERSION 3.8)
project(Project)

set(CMAKE_CXX_STANDARD 11)


# project:
set(SOURCE_FILES src/main.cpp src/Fileio/Fileio.cpp src/Fileio/Fileio.h)
add_executable(Project ${SOURCE_FILES})
target_link_libraries(Project
        restclient-cpp
        curl)


# -----------------------------------------------------------
# unit tests:
set(GTEST_LIBS
        gtest
        gtest_main
        -pthread)

# class Object:
set(TEST_OBJECT
        test/test_Object.cpp
        )

add_executable(test_Object ${TEST_OBJECT})
target_link_libraries(test_Object ${GTEST_LIBS})