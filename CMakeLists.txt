cmake_minimum_required(VERSION 3.8)
project(Project)

set(CMAKE_CXX_STANDARD 11)

# --------------------------------------------------------------------
# project sources:
set(FILEIO_SOURCE
        src/Fileio/Fileio.h
        src/Fileio/Fileio.cpp)

set(WIKI_PAGE_PARSER_SOURCE
        src/WikiPageParser/WikiPageParser.h
        src/WikiPageParser/WikiPageParser.cpp)

set(GRAPH_SOURCE
        src/WordEngine/Graph.h
        src/WordEngine/Graph.cpp)


# --------------------------------------------------------------------
# project:
set(SOURCE_FILES src/main.cpp
        ${FILEIO_SOURCE}
        ${GRAPH_SOURCE}
        ${WIKI_PAGE_PARSER_SOURCE})

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

# Graph
set(GRAPH_TESTS
        ${GRAPH_SOURCE}
        test/test_Graph/test_Graph.cpp)
add_executable(test_Graph ${GRAPH_TESTS})
target_link_libraries(test_Graph ${GTEST_LIBS})