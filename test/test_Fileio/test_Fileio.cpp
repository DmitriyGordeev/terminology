#include <iostream>
#include <gtest/gtest.h>

#include "../../src/Fileio/Fileio.h"

using namespace std;

const string test_folder_prefix = "../test/";


/* Fileio::read() method */
TEST(Fileio_readMethod, test_readNotThrowsAnException)
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

TEST(Fileio_readMethod, test_readThrowsAnException)
{
    string filename = test_folder_prefix + "test_Fileio/resources/some_not_existing_filename.txt";
    string content;
    try {
        content = Fileio::read(filename);
        FAIL();
    }
    catch(exception& e) {
        cout << "Test right behaviour message: " << e.what() << endl;
    }
}

TEST(Fileio_readMethod, test_readValidContent)
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


/* Fileio::write() method */
TEST(Fileio_writeMethod, test_writeNotThrowsAnException)
{
    std::string content = "some new content here\nwith second line";
    try {
        Fileio::write(test_folder_prefix + "test_Fileio/resources/write_test_output.txt", content);
    }
    catch(exception& e) {
        FAIL();
    }
}

TEST(Fileio_writeMethod, test_writeThrowsAnException)
{
    // TODO: create this test case
}

TEST(Fileio_writeMethod, test_writeValidContent)
{
    std::string content = "some new content here\nwith second line";
    try {
        Fileio::write(test_folder_prefix + "test_Fileio/resources/write_test_output.txt", content);
        try {
            string actual = Fileio::read(test_folder_prefix + "test_Fileio/resources/write_test_output.txt");
            EXPECT_EQ(content, actual);
        }
        catch(exception& e) {
            FAIL() << "file was not wrote" << endl;
        }
    }
    catch(exception& e) {
        FAIL();
    }
}



int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

