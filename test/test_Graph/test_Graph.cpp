#include <iostream>
#include <gtest/gtest.h>

#include "../../src/WordEngine/Graph.h"

using namespace std;

class InhGraph: public Graph {
public:
    Node* test_search_r(const string& value, Node* start) {
        return search_r(value, start);
    }

    vector<Node*>& nodes_ref() { return _nodes; }
};

TEST(test_InhGraph, test_search_r__returnsCorrectValue) {

    Node* A1 = new Node("A1", vector<Node*> {
            new Node("A1_A2"),
            new Node("A1_B2"),
            new Node("A1_C2")
    });

    Node* B1 = new Node("B1", vector<Node*> {
            new Node("B1_A2"),
            new Node("B1_B2"),
            new Node("B1_C2")
    });

    Node* C1 = new Node("C1", vector<Node*> {
            new Node("C1_A2"),
            new Node("C1_B2"),
            new Node("C1_C2")
    });

    Node* node = new Node("root", vector<Node*> { A1, B1, C1 });

    InhGraph graph;
    auto& nodes = graph.nodes_ref();
    nodes.push_back(node);

    string item = "C1_A2";
    Node* result = graph.test_search_r(item, nodes[0]);
    EXPECT_FALSE(result == nullptr);
    EXPECT_EQ(item, result->value);
}

// TODO: make different cases for Graph::test_search_r():

int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

