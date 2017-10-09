#ifndef PROJECT_WORDMATRIXEXP_H
#define PROJECT_WORDMATRIXEXP_H

#include <string>

class WordMatrixExp
{
public:
    WordMatrixExp();
    WordMatrixExp(int rows, int cols);
    WordMatrixExp(const WordMatrixExp& object);
    ~WordMatrixExp();

    int rows() const { return _rows; }
    int cols() const { return _cols; }

protected:
    std::string** _matrix;
    int _rows;
    int _cols;

private:

};


#endif //PROJECT_WORDMATRIXEXP_H
