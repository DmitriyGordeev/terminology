#ifndef PROJECT_GRAPH_H
#define PROJECT_GRAPH_H

#include <string>
#include <vector>
#include <iostream>

struct Edge;
struct Node
{
    explicit Node(const std::string& value) {
        this->value = value;
    }

    ~Node() {
        for(auto e : edges) {
            delete e;
            e = nullptr;
        }
        std::cout << "Node::destructed - value = " << value << std::endl;
    }

    std::string value;
    std::vector<Edge*> edges;
};

struct Edge
{
    Edge() = default;
    ~Edge() {
        for(auto e : nodes) {
            delete e;
            e = nullptr;
        }
        std::cout << "Edge::destructed" << std::endl;
    }
    std::vector<Node*> nodes;
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

    std::vector<Node*> _nodes;
    size_t _size;

private:


};


#endif //PROJECT_GRAPH_H
