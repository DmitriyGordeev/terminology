#include <iostream>
#include <gtest/gtest.h>

#include "../../src/Fileio/Fileio.h"

using namespace std;

const string test_folder_prefix = "../test/";

TEST(Fileio, test_readNotThrowsException)
{
    string filename = test_folder_prefix + "test_Fileio/resources/read_test.txt";
    string content;
    try {
        content = Fileio::read(filename);
    }
    catch(exception& e) {
        cout << e.what() << endl;
        FAIL();
    }
}

TEST(Fileio, test_readValidContent)
{
    string filename = test_folder_prefix + "test_Fileio/resources/read_test.txt";
    string content;
    try {
        content = Fileio::read(filename);
        EXPECT_EQ("abc\ndef\nghi", content);
    }
    catch(exception& e) {
        cout << e.what() << endl;
        FAIL();
    }
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

