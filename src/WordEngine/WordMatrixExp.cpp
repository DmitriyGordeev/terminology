#include "WordMatrixExp.h"

using namespace std;

WordMatrixExp::WordMatrixExp() {

    _matrix = nullptr;
    _rows = 0;
    _cols = 0;
}

WordMatrixExp::WordMatrixExp(size_t rows, size_t cols) {

    _rows = rows;
    _cols = cols;
    _matrix = new string*[_rows][_cols];
}

WordMatrixExp::~WordMatrixExp() {

    for(size_t i = 0; i < _rows; i++) {
        delete[] _matrix[i];
        _matrix[i] = nullptr;
    }

    delete[] _matrix;
    _matrix = nullptr;
}
