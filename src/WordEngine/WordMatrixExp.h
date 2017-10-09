#ifndef PROJECT_WORDMATRIXEXP_H
#define PROJECT_WORDMATRIXEXP_H

#include <string>

class WordMatrixExp
{
public:

    // TODO: make test for all these methods:
    WordMatrixExp();
    WordMatrixExp(int rows, int cols);
    WordMatrixExp(const WordMatrixExp& object);
    ~WordMatrixExp();

    int rows() const { return _rows; }
    int cols() const { return _cols; }

    void setValue(const std::string& value, int rowIndex, int colIndex);
    std::string getValue(int rowIndex, int colIndex) const;

protected:
    std::string** _matrix;
    int _rows;
    int _cols;

private:

};


#endif //PROJECT_WORDMATRIXEXP_H
