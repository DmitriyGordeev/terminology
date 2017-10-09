#include <iostream>
#include <gtest/gtest.h>

#include "../../src/WordEngine/WordMatrixExp.h"


TEST(WordMatrixExp, constructorThrowsException) {

    try {
        WordMatrixExp wordMatrixExp(-1, 0);
        FAIL() << "expected exception";
    }
    catch(...) {}
}

TEST(WordMatrixExp, copyConstructorNotThrowsException) {

    WordMatrixExp wordMatrixExp(5, 5);
    WordMatrixExp anotherMatrix(wordMatrixExp);
}



int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}