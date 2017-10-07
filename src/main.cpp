#include <iostream>
#include <string>
#include <restclient-cpp/connection.h>
#include <restclient-cpp/restclient.h>

#include "Fileio/Fileio.h"
#include "WikiPageParser/WikiPageParser.h"

using namespace std;


int main(int argc, char** argv) {

    system("mkdir -p resource");

//    std::string url = "https://ru.wikipedia.org/wiki/Юпитер#.D0.A2.D1.80.D0.BE.D1.8F.D0.BD.D1.81.D0.BA.D0.B8.D0.B5_.D0.B0.D1.81.D1.82.D0.B5.D1.80.D0.BE.D0.B8.D0.B4.D1.8B";
//    RestClient::Response r = RestClient::get(url);
//    Fileio::write("resource/jupiter.wikipedia.org.html", r.body);


    string title = WikiPageParser::getArticle();
    cout << WikiPageParser::getArticle() << endl;


    return 0;
}