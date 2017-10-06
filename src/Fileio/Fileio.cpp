#include <fstream>
#include "Fileio.h"

using namespace std;

// throws runtime_error
std::string Fileio::read(const std::string& filename) {

    ifstream file_input(filename.c_str());
    if(file_input.fail()) {
        throw runtime_error("Fileio::readfile(" + filename + "): not found such file");
    }

    string file_content;
    string line;
    while(getline(file_input, line)) {
        file_content.append(line + "\n");
    }
    file_input.close();

    // remove last \n:
    file_content.pop_back();
    return file_content;
}

// throws runtime_error
void Fileio::write(const std::string& filename, const std::string& content) {

    ofstream file_output(filename.c_str());
    if(file_output.fail()) {
        throw runtime_error("Fileio::write(" + filename + ", <somecontent>): not found such file");
    }

    file_output << content;
    file_output.close();
}