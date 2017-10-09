#include "Graph.h"

Graph::Graph() { _size = 0; }
Graph::~Graph() = default;


Node* Graph::add(const std::string& word) {

}

Node* Graph::search(const std::string& value) {

}



/* protected: */
Node* Graph::search_r(const std::string& value, Node* start) {

    if(!start) {
        return nullptr;
    }

    if(start->word == value) {
        return start;
    }

    for(auto itr : start->siblings)
        return search_r(value, itr);
}