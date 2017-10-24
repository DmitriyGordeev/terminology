#ifndef PROJECT_GRAPH_H
#define PROJECT_GRAPH_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <set>

enum EdgeType {
    NOT_CONNECTED,
    DIRECT,      // the first is connected to the second
    REVERSE,     // the second is connected to the first
    DOUBLE_F,    // both have a connection to each other, but the first dominates  (shared_ptr vs weak_ptr)
    DOUBLE_S,    // both have a connection to each other, but the second dominates (weak_ptr vs shared_ptr)
    FIRST_NF,    // first node is not found inside a Graph
    SECOND_NF,   // second node is not found inside a Graph
    NF           // both are not found inside a Graph
};


struct Node
{
    explicit Node(const std::string& value) {
        this->value = value;
    }

    ~Node() {}

    void connect(const std::shared_ptr<Node>& other);
    std::shared_ptr<Node> find_sp(const std::string& value);
    std::shared_ptr<Node> find_wp(const std::string& value);

    std::string value;
    std::vector<std::shared_ptr<Node>> sp_nodes;
    std::vector<std::weak_ptr<Node>> wp_nodes;
};


class Graph
{
public:
    Graph();
    ~Graph();

    std::shared_ptr<Node> add(const std::string& value);
    std::shared_ptr<Node> add(const std::string& value, const std::vector<std::string>& links);
    std::shared_ptr<Node> search(const std::string& value);


    EdgeType areConnected(const std::string& A, const std::string& B);

    size_t size() const { return _size; }

protected:
    std::shared_ptr<Node> search_r(const std::string &value,
                                   std::shared_ptr<Node> start);

    std::vector<std::shared_ptr<Node>> _nodes;
    size_t _size;

private:


};


#endif //PROJECT_GRAPH_H
