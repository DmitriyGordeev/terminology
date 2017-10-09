#ifndef PROJECT_GRAPH_H
#define PROJECT_GRAPH_H

#include <string>
#include <vector>


struct Node
{
    std::string word;
    std::vector<Node*> siblings;
};


class Graph
{
public:
    Graph();
    ~Graph();

    Node* add(const std::string& value);
    Node* search(const std::string& value);

protected:
    Node* search_r(const std::string& value, Node* start);

    std::vector<Node*> _nodes;
    size_t _size;

private:


};


#endif //PROJECT_GRAPH_H