#include "Graph.h"

using namespace std;

Graph::Graph() { _size = 0; }
Graph::~Graph() = default;


Node* Graph::add(const std::string& value) {

    Node* search_result = search(value);
    if(search_result) {
        return search_result;
    }

    // TODO: play with vector of raw pointers and vector of smart pointers
    search_result = new Node(value);
    _nodes.push_back(search_result);
    _size++;
    return search_result;
}

Node* Graph::search(const std::string& value) {

    for(auto itr : _nodes)
    {
        Node* r = search_r(value, itr);
        if(r) {
            if(r->value == value)
                return r;
        }
    }

    return nullptr;
}


Node* Graph::accept(Node* node,
             const std::vector<std::string>& links) {

}

/* protected: */
Node* Graph::search_r(const std::string& value, Node* start) {

    if(!start) {
        return nullptr;
    }

    if(start->value == value) {
        return start;
    }

    if(start->siblings.empty()) {
        return nullptr;
    }

    for(auto itr : start->siblings)
    {
        Node* r = search_r(value, itr);
        if(r) {
            if(r->value == value)
                return r;
        }
    }

    return nullptr;
}
