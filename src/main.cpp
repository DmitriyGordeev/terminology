#include <iostream>
#include "WordEngine/Graph.h"
using namespace std;

int main(int argc, char** argv) {

    Graph graph;
    graph.add("Юпитер", vector<string> {
            "Солнце",
            "Планета",
            "Космос"
    } );



    return 0;
}