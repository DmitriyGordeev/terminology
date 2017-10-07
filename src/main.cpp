#include <iostream>
#include <string>
#include <restclient-cpp/connection.h>
#include <restclient-cpp/restclient.h>

#include "Fileio/Fileio.h"
#include "WikiPageParser/WikiPageParser.h"

using namespace std;


int main(int argc, char** argv) {

    system("mkdir -p resource");


    string content;
    try {
       content = Fileio::read("resource/jupiter.wikipedia.org.html");
    }
    catch(exception& e) {
        cout << e.what() << endl;
        return 0;
    }

    string data = WikiPageParser::gumboExample(content);
    cout << data << endl;

    return 0;
}