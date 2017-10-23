#ifndef PROJECT_GRAPH_H
#define PROJECT_GRAPH_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <set>

struct Node
{
    explicit Node(const std::string& value) {
        this->value = value;
    }

    ~Node() {
        std::cout << "Node::destructed - value = " << value << std::endl;
    }

    void connect(const std::shared_ptr<Node>& other);

    std::string value;
    std::vector<std::shared_ptr<Node>> sp_nodes;
    std::vector<std::weak_ptr<Node>> wp_nodes;
};


class Graph
{
public:
    Graph();
    ~Graph();

    Node* add(const std::string& value);
    Node* search(const std::string& value);
    Node* accept(Node* node, const std::vector<std::string>& links);

    size_t size() const { return _size; }

protected:
    Node* search_r(const std::string& value, Node* start);

    std::vector<std::shared_ptr<Node>> _nodes;
    size_t _size;

private:


};


#endif //PROJECT_GRAPH_H
