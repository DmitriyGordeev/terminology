#include <iostream>
#include <string>
#include <restclient-cpp/connection.h>
#include <restclient-cpp/restclient.h>

#include "Fileio/Fileio.h"

using namespace std;

int main(int argc, char** argv) {

    system("mkdir -p resource");

    std::string url = "https://ru.wikipedia.org/wiki/Заглавная_страница";
    RestClient::Response r = RestClient::get(url);

    Fileio::write("resource/wikipedia.org", r.body);

    return 0;
}