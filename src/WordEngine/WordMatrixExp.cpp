#include <stdexcept>
#include "WordMatrixExp.h"

using namespace std;

WordMatrixExp::WordMatrixExp() = default;

WordMatrixExp::WordMatrixExp(size_t rows, size_t cols) {

    if(rows < 0 || cols < 0)
        throw runtime_error("constructor WordMatrixExp(size_t rows, size_t cols) has negative parameter(s)");

    _data.reserve(rows);
    for(auto v : _data)
        v.reserve(cols);
}

WordMatrixExp::WordMatrixExp(const WordMatrixExp& object) {
    _data = object._data;
}

WordMatrixExp::~WordMatrixExp() = default;



void WordMatrixExp::setValue(const string& value, size_t rowIndex, size_t colIndex) {

    vector<string>& row_ref = _data.at(rowIndex);
    string& element_ref = row_ref.at(colIndex);
    element_ref = value;
}

string WordMatrixExp::getValue(size_t rowIndex, size_t colIndex) const {

    const vector<string>& row = _data.at(rowIndex);
    const string& element = row.at(colIndex);
    return element;
}

