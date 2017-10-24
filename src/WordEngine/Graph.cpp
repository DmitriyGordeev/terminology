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
std::shared_ptr<Node> Node::find_sp(const std::string& value) {

    auto sp_itr = find_if(sp_nodes.begin(),
                       sp_nodes.end(),
                       [value](const shared_ptr<Node>& p)
                       {
                           return (p->value == value);
                       });

    if(sp_itr != sp_nodes.end()) {
        return *sp_itr;
    }

    return nullptr;
}
std::shared_ptr<Node> Node::find_wp(const std::string& value) {

    auto wp_itr = find_if(wp_nodes.begin(),
                          wp_nodes.end(),
                          [value](const weak_ptr<Node>& p) {
                              return (p.lock()->value == value);
                          });

    if(wp_itr != wp_nodes.end()) {
        return (*wp_itr).lock();
    }

    return nullptr;
}

Graph::Graph() { _size = 0; }
Graph::~Graph() = default;


shared_ptr<Node> Graph::add(const std::string& value) {

    shared_ptr<Node> search_result = search(value);
    if(search_result) {
        return search_result;
    }

    search_result = make_shared<Node>(value);
    _nodes.push_back(search_result);
    _size++;
    return search_result;
}

std::shared_ptr<Node> Graph::add(const std::string& value, const std::vector<std::string>& links) {

    shared_ptr<Node> search_result = search(value);
    if(search_result) {

        for(const auto& s : links) {
            auto p = add(s);
            search_result->connect(p);
        }
    }
    else {
        search_result = make_shared<Node>(value);
        _nodes.push_back(search_result);
        _size++;

        for(const auto& s : links) {
            auto p = add(s);
            search_result->connect(p);
        }
    }

    return search_result;
}

shared_ptr<Node> Graph::search(const std::string& value) {

    for(const auto& itr : _nodes)
    {
        auto r = search_r(value, itr);
        if(r) {
            if(r->value == value)
                return r;
        }
    }

    return nullptr;
}

EdgeType Graph::areConnected(const std::string& A, const std::string& B) {

    auto sp_A = search(A);
    auto sp_B = search(B);

    if(sp_A == nullptr && sp_B == nullptr) {
        return EdgeType::NF;
    }

    if(sp_A == nullptr) {
        return EdgeType::FIRST_NF;
    }

    if(sp_B == nullptr) {
        return EdgeType::SECOND_NF;
    }


    if(sp_A->find_sp(B)) {
        if(sp_B->find_wp(A)) {
            return EdgeType::DOUBLE_F;
        } else
            return EdgeType::DIRECT;
    }
    else if(sp_A->find_wp(B)) {
        return EdgeType::DOUBLE_S;
    }


    if(sp_B->find_sp(A)) {
        return EdgeType::REVERSE;
    }
    else
        return EdgeType::NOT_CONNECTED;

}

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
