#include <iostream>
#include <memory>
#include <algorithm>
#include <gtest/gtest.h>

#include "../../src/WordEngine/Graph.h"

using namespace std;

class TestGraph: public Graph
{
public:
    TestGraph() : Graph() {}

    std::shared_ptr<Node> test_search_r(const std::string& value,
                                        const std::shared_ptr<Node>& start) {
        return search_r(value, start);
    }
    std::vector<std::shared_ptr<Node>>& getNodes() { return _nodes; }

};


TEST(VectorPointers, cyclingReference) {

    shared_ptr<Node> a = make_shared<Node>("A");
    shared_ptr<Node> b = make_shared<Node>("B");
    shared_ptr<Node> c = make_shared<Node>("C");

    a->connect(b);
    a->connect(c);

    b->connect(a);
    b->connect(c);

    c->connect(a);
    c->connect(b);

}



TEST(TestGraph, search_r__returnsCorrectValue) {

    shared_ptr<Node> a = make_shared<Node>("A");
    shared_ptr<Node> b = make_shared<Node>("B");
    shared_ptr<Node> c = make_shared<Node>("C");

    a->connect(b);
    a->connect(c);
    b->connect(c);

    TestGraph graph;
    auto& nodes = graph.getNodes();
    nodes.push_back(a);

    auto r = graph.test_search_r("C", b);
    EXPECT_FALSE(r == nullptr);
    EXPECT_TRUE(r.get() == c.get());
    EXPECT_TRUE(c->value == "C");

}

TEST(TestGraph, search_r__returnsNullptr) {

    shared_ptr<Node> a = make_shared<Node>("A");
    shared_ptr<Node> b = make_shared<Node>("B");
    shared_ptr<Node> c = make_shared<Node>("C");

    a->connect(b);
    a->connect(c);
    b->connect(c);

    TestGraph graph;
    auto& nodes = graph.getNodes();
    nodes.push_back(a);

    auto r = graph.test_search_r("D", b);
    EXPECT_TRUE(r == nullptr);
}



TEST(TestGraph, search_returnsCorrectValue) {

    shared_ptr<Node> a = make_shared<Node>("A");
    shared_ptr<Node> b = make_shared<Node>("B");
    shared_ptr<Node> c = make_shared<Node>("C");

    a->connect(b);
    a->connect(c);
    b->connect(c);

    TestGraph graph;
    auto& nodes = graph.getNodes();
    nodes.push_back(a);


    EXPECT_FALSE(graph.search("A") == nullptr);
    EXPECT_FALSE(graph.search("B") == nullptr);
    EXPECT_FALSE(graph.search("C") == nullptr);
}

TEST(TestGraph, search_returnsNullptr) {

    shared_ptr<Node> a = make_shared<Node>("A");
    shared_ptr<Node> b = make_shared<Node>("B");
    shared_ptr<Node> c = make_shared<Node>("C");

    a->connect(b);
    a->connect(c);
    b->connect(c);

    TestGraph graph;
    auto& nodes = graph.getNodes();
    nodes.push_back(a);

    EXPECT_TRUE(graph.search("D") == nullptr);
}



TEST(TestGraph, add_returnsCorrectValueOnEmpty) {

    TestGraph graph;
    auto s = graph.add("A");
    EXPECT_FALSE(s == nullptr);
    EXPECT_EQ(s->value, "A");
    EXPECT_EQ(graph.size(), 1);
}

TEST(TestGraph, add_doesNotAddsDuplicate) {

    TestGraph graph;
    auto s1 = graph.add("A");
    auto s2 = graph.add("A");
    EXPECT_EQ(s1, s2);
    EXPECT_EQ(graph.size(), 1);

}

TEST(TestGraph, add_withLinks_Empty) {

    TestGraph graph;
    auto a = graph.add("A", vector<string> { "B", "C" });

    EXPECT_FALSE(a == nullptr);
    EXPECT_EQ("A", a->value);

    auto b = graph.search("B");
    EXPECT_FALSE(b == nullptr);
    EXPECT_EQ("B", b->value);

    auto c = graph.search("C");
    EXPECT_FALSE(c == nullptr);
    EXPECT_EQ("C", c->value);

    EXPECT_EQ(3, graph.size());
}

TEST(TestGraph, add_withLinks_SmthAlreadyExists) {

    TestGraph graph;
    graph.add("C");
    auto a = graph.add("A", vector<string> { "B", "C" });

    EXPECT_FALSE(a == nullptr);
    EXPECT_EQ("A", a->value);

    auto b = graph.search("B");
    EXPECT_FALSE(b == nullptr);
    EXPECT_EQ("B", b->value);

    EXPECT_EQ(3, graph.size());
}


int main(int argc, char** argv) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

