#ifndef PROJECT_GRAPH_H
#define PROJECT_GRAPH_H

#include <string>
#include <vector>
#include <iostream>
#include <memory>

struct Node
{
    explicit Node(const std::string& value) {
        this->value = value;
    }

    Node(const std::string& value, const std::vector<Node*>& siblings) {
        this->value = value;
        for(auto p : siblings) {
            this->siblings.push_back(std::shared_ptr<Node>(p));
        }
    }


    std::string value;
    std::vector<std::shared_ptr<Node>> siblings;
};


class Graph
{
public:
    Graph();
    ~Graph();

    Node* add(const std::string& value);
    Node* search(const std::string& value);
    Node* accept(const std::string& value, const std::vector<std::string>& links);

    size_t size() const { return _size; }

protected:
    Node* search_r(const std::string& value, Node* start);

    std::vector<std::shared_ptr<Node>> _nodes;
    size_t _size;

private:


};


#endif //PROJECT_GRAPH_H
