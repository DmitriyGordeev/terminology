#include <iostream>
#include <memory>
#include <algorithm>
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



//TEST(test_InhGraph, test_search_r__returnsCorrectValue) {
//
//    Node* A1 = new Node("A1", vector<Node*> {
//            new Node("A1_A2"),
//            new Node("A1_B2"),
//            new Node("A1_C2")
//    });
//
//    Node* B1 = new Node("B1", vector<Node*> {
//            new Node("B1_A2"),
//            new Node("B1_B2"),
//            new Node("B1_C2")
//    });
//
//    Node* C1 = new Node("C1", vector<Node*> {
//            new Node("C1_A2"),
//            new Node("C1_B2"),
//            new Node("C1_C2")
//    });
//
//    Node* node = new Node("root", vector<Node*> { A1, B1, C1 });
//
//    InhGraph graph;
//    auto& nodes = graph.nodes_ref();
//    nodes.push_back(node);
//
//    string item = "C1_A2";
//    Node* result = graph.test_search_r(item, nodes[0]);
//    EXPECT_FALSE(result == nullptr);
//    EXPECT_EQ(item, result->value);
//
//    delete node;
//    delete C1;
//    delete B1;
//    delete A1;
//}
//
//TEST(test_InhGraph, test_search_r__returnsNullptr) {
//
//    Node* A1 = new Node("A1", vector<Node*> {
//            new Node("A1_A2"),
//            new Node("A1_B2"),
//            new Node("A1_C2")
//    });
//
//    Node* B1 = new Node("B1", vector<Node*> {
//            new Node("B1_A2"),
//            new Node("B1_B2"),
//            new Node("B1_C2")
//    });
//
//    Node* C1 = new Node("C1", vector<Node*> {
//            new Node("C1_A2"),
//            new Node("C1_B2"),
//            new Node("C1_C2")
//    });
//
//    Node* node = new Node("root", vector<Node*> { A1, B1, C1 });
//
//    InhGraph graph;
//    auto& nodes = graph.nodes_ref();
//    nodes.push_back(node);
//
//    string item = "some not existing string";
//    Node* result = graph.test_search_r(item, nodes[0]);
//    EXPECT_TRUE(result == nullptr) << "result = " << result->value;
//
//    delete node;
//    delete C1;
//    delete B1;
//    delete A1;
//}
//
//TEST(test_InhGraph, test_search_r__returnsNullptrOnEmpty) {
//
//    Node* node = new Node("root");
//
//    InhGraph graph;
//    auto& nodes = graph.nodes_ref();
//    nodes.push_back(node);
//
//    string item = "some not existing string";
//    Node* result = graph.test_search_r(item, nodes[0]);
//    EXPECT_TRUE(result == nullptr) << "result = " << result->value;
//
//    delete node;
//}
//
//TEST(test_InhGraph, search_returnsCorrectValue) {
//
//    Node* A1 = new Node("A1", vector<Node*> {
//            new Node("A1_A2"),
//            new Node("A1_B2"),
//            new Node("A1_C2")
//    });
//
//    Node* B1 = new Node("B1", vector<Node*> {
//            new Node("B1_A2"),
//            new Node("B1_B2"),
//            new Node("B1_C2")
//    });
//
//    Node* C1 = new Node("C1", vector<Node*> {
//            new Node("C1_A2"),
//            new Node("C1_B2"),
//            new Node("C1_C2")
//    });
//
//    Node* node = new Node("root", vector<Node*> { A1, B1, C1 });
//
//    InhGraph graph;
//    auto& nodes = graph.nodes_ref();
//    nodes.push_back(node);
//
//    string item = "C1_A2";
//    Node* result = graph.search(item);
//    EXPECT_FALSE(result == nullptr);
//    EXPECT_EQ(item, result->value);
//
//    delete node;
//    delete C1;
//    delete B1;
//    delete A1;
//}
//
//TEST(test_InhGraph, search_returnsNullptr) {
//
//    Node* A1 = new Node("A1", vector<Node*> {
//            new Node("A1_A2"),
//            new Node("A1_B2"),
//            new Node("A1_C2")
//    });
//
//    Node* B1 = new Node("B1", vector<Node*> {
//            new Node("B1_A2"),
//            new Node("B1_B2"),
//            new Node("B1_C2")
//    });
//
//    Node* C1 = new Node("C1", vector<Node*> {
//            new Node("C1_A2"),
//            new Node("C1_B2"),
//            new Node("C1_C2")
//    });
//
//    Node* node = new Node("root", vector<Node*> { A1, B1, C1 });
//
//    InhGraph graph;
//    auto& nodes = graph.nodes_ref();
//    nodes.push_back(node);
//
//    string item = "some string";
//    Node* result = graph.search(item);
//    EXPECT_TRUE(result == nullptr);
//
//    delete node;
//    delete C1;
//    delete B1;
//    delete A1;
//}
//
//TEST(test_InhGraph, add_returnsCorrectValueOnEmpty) {
//
//    InhGraph graph;
//    EXPECT_EQ(0, graph.size());
//
//    string value = "some random string";
//    Node* ptr = graph.add(value);
//
//    EXPECT_FALSE(ptr == nullptr);
//    EXPECT_EQ(value, ptr->value);
//    EXPECT_EQ(1, graph.size());
//}
//
//TEST(test_InhGraph, add_doesNotAddsDuplicate) {
//
//    // TODO: check if TEST() macroses are executed separately or ...
//
//    InhGraph graph;
//    string value = "value";
//    Node* ptr = graph.add(value);
//    Node* same_ptr = graph.add(value);
//
//    EXPECT_FALSE(ptr == nullptr);
//    EXPECT_FALSE(same_ptr == nullptr);
//    EXPECT_EQ(ptr, same_ptr);
//    EXPECT_EQ(1, graph.size());
//}

TEST(VectorPointers, cyclingReference) {

    Node* A = new Node("A");
    Node* B = new Node("B");

    Edge* A_B = new Edge();
    A_B->nodes.insert(B);

    Edge* B_A = new Edge();
    B_A->nodes.insert(A);

    A->edges.push_back(A_B);
    B->edges.push_back(B_A);


    // remove occurence of B:
    A_B->nodes.erase(B);
    B->edges.clear();
    B_A->nodes.clear();

    auto itr = std::find(A->edges.begin(), A->edges.end(), A_B);
    A->edges.erase(itr);

    delete B_A; B_A = nullptr;
    delete A_B; A_B = nullptr;
    delete B; B = nullptr;
    delete A; A = nullptr;

}

int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

