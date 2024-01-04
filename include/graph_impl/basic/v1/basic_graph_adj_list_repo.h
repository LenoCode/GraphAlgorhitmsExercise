//
// Created by leno on 02.01.24..
//

#ifndef BASIC_GRAPH_ADJ_LIST_REPO_H
#define BASIC_GRAPH_ADJ_LIST_REPO_H

#include <interface/graph_adt.h>

using namespace std;

class GraphImplAdjList : Graph {
private:
    //Adj_matrix, this represents all the possible edges;

    struct node {
        int data;
        node* link = nullptr;
    };

    typedef node* link;
    node** edges;

    const int V_SIZE;
    int E_SIZE;

    int findVerticeIndex(int v);

public:
    GraphImplAdjList(int v);
    ~GraphImplAdjList();

    int V() const override;

    int E() const override;

    bool directed() const override;

    bool cycle() const override;

    bool DFS_print() const override;

    int insert(Edge) override;

    int remove(Edge) override;

    bool edge(int, int) override;

    void verticesEdges(int v,int* array,int foundElements);

    int findEdgesCount(int v);

};

#endif //BASIC_GRAPH_ADJ_LIST_REPO_H
