#ifndef PROJECT_WORDMATRIXEXP_H
#define PROJECT_WORDMATRIXEXP_H

#include <string>
#include <vector>

typedef std::vector<std::vector<std::string>> SMatrix;

class WordMatrixExp
{
public:

    // TODO: make test for all these methods:
    WordMatrixExp();
    WordMatrixExp(size_t rows, size_t cols);
    WordMatrixExp(const WordMatrixExp& object);
    ~WordMatrixExp();

    size_t rows() const {
        return _data.size();
    }
    size_t cols() const {
        if(_data.empty())
            return 0;

        return _data[0].size();
    }

    void setValue(const std::string& value, size_t rowIndex, size_t colIndex);
    std::string getValue(size_t rowIndex, size_t colIndex) const;

protected:
    SMatrix _data;

private:

};


#endif //PROJECT_WORDMATRIXEXP_H
