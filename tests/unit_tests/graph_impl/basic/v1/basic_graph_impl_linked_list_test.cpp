//
// Created by leno on 04.01.24..
//
#include <core_header.h>
#include <graph_impl/basic/v1/basic_graph_adj_list_repo.h>


TEST(GraphImplV1,GraphBasicLinkedListRepresentation) {
    TEST_DESCRIPTION("GraphBasicLinkedListRepresentation","Testing basic creation of graph with linked list representation")

        GraphImplAdjList graph{5};

        graph.insert(Edge{1,2});
        graph.insert(Edge{1,3});

        ASSERT_TRUE(graph.edge(1,2));
        ASSERT_TRUE(graph.edge(1,3));
        ASSERT_TRUE(graph.edge(3,1));
        ASSERT_TRUE(graph.edge(2,1));
}


TEST(GraphImplV1,GraphBasicLinkedListRepresentationRemovingEdge) {
    TEST_DESCRIPTION("GraphBasicLinkedListRepresentation","Testing removing edge from a graph represented like a linked list")

    GraphImplAdjList graph{5};

    graph.insert(Edge{1,2});
    graph.insert(Edge{1,3});
    graph.insert(Edge{1,4});

    ASSERT_TRUE(graph.edge(1,2));
    ASSERT_TRUE(graph.edge(1,3));


    graph.remove(Edge{1,3});

    ASSERT_FALSE(graph.edge(1,3));
    ASSERT_TRUE(graph.edge(1,2));
    ASSERT_TRUE(graph.edge(1,4));

}




int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}