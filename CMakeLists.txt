cmake_minimum_required(VERSION 3.8)
project(Project)

set(CMAKE_CXX_STANDARD 11)


# project modules:
set(FILEIO_SOURCE
        src/Fileio/Fileio.h
        src/Fileio/Fileio.cpp)

set(WIKI-PAGE-PARSER_SOURCE
        src/WikiPageParser/WikiPageParser.h
        src/WikiPageParser/WikiPageParser.cpp)


# project:
set(SOURCE_FILES src/main.cpp
        ${FILEIO_SOURCE}
        ${WIKI-PAGE-PARSER_SOURCE})

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
        ${FILEIO_SOURCE}
        test/test_Fileio/test_Fileio.cpp)

add_executable(test_Fileio ${TEST_OBJECT})
target_link_libraries(test_Fileio ${GTEST_LIBS})