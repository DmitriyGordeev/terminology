#include "Graph.h"
#include <algorithm>

using namespace std;

void Node::connect(const shared_ptr<Node>& p_node) {

    auto itr = find_if(p_node->sp_nodes.begin(),
                       p_node->sp_nodes.end(),
                       [this](const shared_ptr<Node>& p)
                       {
                           return (p.get() == this);
                       });

    if(itr != p_node->sp_nodes.end()) {
        wp_nodes.push_back(shared_ptr<Node>(p_node));
    }
    else {
        sp_nodes.push_back(p_node);
    }
}

Graph::Graph() { _size = 0; }
Graph::~Graph() = default;


//shared_ptr<Node> Graph::add(const std::string& value) {
//
//    Node* search_result = search(value);
//    if(search_result) {
//        return search_result;
//    }
//
//    // TODO: play with vector of raw pointers and vector of smart pointers
//    search_result = new Node(value);
//    _nodes.push_back(search_result);
//    _size++;
//    return search_result;
//}

shared_ptr<Node> Graph::search(const std::string& value) {

    for(auto itr : _nodes)
    {
        auto r = search_r(value, itr);
        if(r) {
            if(r->value == value)
                return r;
        }
    }

    return nullptr;
}

//
//
//Node* Graph::accept(Node* node,
//             const std::vector<std::string>& links) {
//
//}
//
/* protected: */
shared_ptr<Node> Graph::search_r(const std::string& value,
                                 const shared_ptr<Node>& start) {

    if(!start) {
        return nullptr;
    }

    if(start->value == value) {
        return start;
    }

    if(start->sp_nodes.empty() && start->wp_nodes.empty()) {
        return nullptr;
    }

    for(const auto& e : start->sp_nodes) {
        auto r = search_r(value, e);
        if(r) {
            if(r->value == value)
                return r;
        }
    }

    for(const auto& e : start->wp_nodes) {
        auto r = search_r(value, e.lock());
        if(r) {
            if(r->value == value)
                return r;
        }
    }

    return nullptr;
}
