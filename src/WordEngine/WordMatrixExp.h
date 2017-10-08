#ifndef PROJECT_WORDMATRIXEXP_H
#define PROJECT_WORDMATRIXEXP_H

#include <string>

class WordMatrixExp
{
public:
    WordMatrixExp();
    WordMatrixExp(size_t rows, size_t cols);
    ~WordMatrixExp();

protected:
    std::string** _matrix;
    size_t _rows;
    size_t _cols;

private:

};


#endif //PROJECT_WORDMATRIXEXP_H
