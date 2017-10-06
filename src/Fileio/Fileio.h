#ifndef PROJECT_FILEIO_H
#define PROJECT_FILEIO_H

#include <fstream>
#include <string>

class Fileio
{
public:
    static std::string read(const std::string& filename);
    static std::string write(const std::string& filename, const std::string& content);
};


#endif //PROJECT_FILEIO_H
