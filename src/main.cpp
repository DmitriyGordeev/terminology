#include <iostream>
#include <string>
#include <restclient-cpp/connection.h>
#include <restclient-cpp/restclient.h>

#include "Fileio/Fileio.h"

using namespace std;


int main() {

    std::string url = "https://ru.wikipedia.org/wiki/Заглавная_страница";
    RestClient::Response r = RestClient::get(url);

    cout << r.body << endl;

    return 0;
}