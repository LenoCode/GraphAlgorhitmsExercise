//
// Created by leno on 20.12.23..
//
#include <core_header.h>
#include <graph_impl/basic/v1/basic_graph_impl.h>


/**
 * Testing basic graph creation and checking if the structure is ok
 *  Acyclic
 *  Edges
 *
 *
 *
 */
TEST(GraphImplV1,TestBasicGraphImplementation) {
    TEST_DESCRIPTION("TestBasicGraphImplementation","Testing basic graph creation and check if structure is in valid state")

    //INIT
    GraphImpl graph_impl{10};

    //WHEN
    graph_impl.insert(Edge{1,3});
    graph_impl.insert(Edge{1,2});
    graph_impl.insert(Edge{2,4});
    graph_impl.insert(Edge{2,7});
    graph_impl.insert(Edge{3,6});
    graph_impl.insert(Edge{3,5});
    graph_impl.insert(Edge{5,9});
    graph_impl.insert(Edge{5,8});
    graph_impl.insert(Edge{8,10});

    //THEN checking double. Because graph is undirected, that means when we put 1-2 it is also 2-1 edge
    ASSERT_EQ(9,graph_impl.E());
    ASSERT_EQ(true,graph_impl.edge(2,4));
    ASSERT_EQ(true,graph_impl.edge(4,2));

    ASSERT_EQ(true,graph_impl.edge(3,1));
    ASSERT_EQ(true,graph_impl.edge(3,1));


    //WHEN
    int foundCount = graph_impl.findEdgesCount(1);
    int nodesConnectedTo1[foundCount];

    graph_impl.verticesEdges(1,nodesConnectedTo1,foundCount);

    //THEN
    int expected[] = {3,2};
    ASSERT_EQ(2,foundCount);
    ASSERT_TRUE(areArraysEqual(expected,foundCount,nodesConnectedTo1,foundCount));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}