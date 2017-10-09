cmake_minimum_required(VERSION 3.8)
project(Project)

set(CMAKE_CXX_STANDARD 11)


# project modules:
set(FILEIO_SOURCE
        src/Fileio/Fileio.h
        src/Fileio/Fileio.cpp)

set(WIKI_PAGE_PARSER_SOURCE
        src/WikiPageParser/WikiPageParser.h
        src/WikiPageParser/WikiPageParser.cpp)

set(WORD_MATRIX_CLASS_SOURCE
        src/WordEngine/WordMatrixExp.h
        src/WordEngine/WordMatrixExp.cpp)


# project:
set(SOURCE_FILES src/main.cpp
        ${FILEIO_SOURCE}
        ${WIKI_PAGE_PARSER_SOURCE}
        ${WORD_MATRIX_CLASS_SOURCE} src/WordEngine/MatrixCreator.cpp src/WordEngine/MatrixCreator.h)

add_executable(Project ${SOURCE_FILES})
target_link_libraries(Project
        gumbo
        gq
        restclient-cpp
        curl)



# TODO: exclude all tests to subprojects:
# -----------------------------------------------------------
# unit tests:
set(GTEST_LIBS
        gtest
        gtest_main
        -pthread)


# Fileio
set(FILEIO_TESTS
        ${FILEIO_SOURCE}
        test/test_Fileio/test_Fileio.cpp)
add_executable(test_Fileio ${FILEIO_TESTS})
target_link_libraries(test_Fileio ${GTEST_LIBS})


# WordMatrixExp
set(WORD_MATRIX_EXP_TESTS
        ${WORD_MATRIX_CLASS_SOURCE}
        test/test_WordMatrixExp/test_WordMatrixExp.cpp)
add_executable(test_WordMatrixExp ${WORD_MATRIX_EXP_TESTS})
target_link_libraries(test_WordMatrixExp ${GTEST_LIBS})