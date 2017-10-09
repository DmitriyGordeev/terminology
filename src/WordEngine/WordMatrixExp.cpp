#include <stdexcept>
#include "WordMatrixExp.h"

using namespace std;

WordMatrixExp::WordMatrixExp() {

    _matrix = nullptr;
    _rows = 0;
    _cols = 0;
}

WordMatrixExp::WordMatrixExp(int rows, int cols) {

    if(rows < 0 || cols < 0)
        throw runtime_error("constructor WordMatrixExp(size_t rows, size_t cols) has negative parameter(s)");

    _rows = rows;
    _cols = cols;
    _matrix = new string*[_rows];
    for(size_t i = 0; i < _cols; i++) {
        _matrix[i] = new string[_cols];
    }
}

WordMatrixExp::WordMatrixExp(const WordMatrixExp& object) {

    _rows = object._rows;
    _cols = object._cols;

    _matrix = new string*[_rows];
    for(size_t i = 0; i < _cols; i++) {
        _matrix[i] = new string[_cols];
    }

    for(int i = 0; i < _rows; i++)
        for(int j = 0; j < _cols; j++)
            _matrix[i][j] = object._matrix[i][j];

}

WordMatrixExp::~WordMatrixExp() {

    for(size_t i = 0; i < _rows; i++) {
        delete[] _matrix[i];
        _matrix[i] = nullptr;
    }

    delete[] _matrix;
    _matrix = nullptr;
}



void WordMatrixExp::setValue(const string& value, int rowIndex, int colIndex) {

    if(rowIndex < 0 || rowIndex >= _rows) {
        throw runtime_error("WordMatrixExp::setValue(value, rowIndex, colIndex) : rowIndex out or range");
    }

    if(colIndex < 0 || colIndex >= _cols) {
        throw runtime_error("WordMatrixExp::setValue(value, rowIndex, colIndex) : colIndex out or range");
    }

    if(_matrix != nullptr) {
        _matrix[rowIndex][colIndex] = value;
    }
}

string WordMatrixExp::getValue(int rowIndex, int colIndex) const {

    if(rowIndex < 0 || rowIndex >= _rows) {
        throw runtime_error("WordMatrixExp::getValue(rowIndex, colIndex) : rowIndex out or range");
    }

    if(colIndex < 0 || colIndex >= _cols) {
        throw runtime_error("WordMatrixExp::getValue(rowIndex, colIndex) : colIndex out or range");
    }

    if(_matrix == nullptr) {
        throw runtime_error("WordMatrixExp::getValue(rowIndex, colIndex) : inner data pointer is null");
    }

    return _matrix[rowIndex][colIndex];
}
