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

    ~Node() {}

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

    std::shared_ptr<Node> add(const std::string& value);
    std::shared_ptr<Node> add(const std::string& value, const std::vector<std::string>& links);
    std::shared_ptr<Node> search(const std::string& value);

    int areConnected(const std::string& A, const std::string& B);

    size_t size() const { return _size; }

protected:
    std::shared_ptr<Node> search_r(const std::string& value,
                                   const std::shared_ptr<Node>& start);

    std::vector<std::shared_ptr<Node>> _nodes;
    size_t _size;

private:


};


#endif //PROJECT_GRAPH_H
