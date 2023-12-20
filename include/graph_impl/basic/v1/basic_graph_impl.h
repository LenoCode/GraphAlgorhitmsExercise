//
// Created by leno on 20.12.23..
//
#include <interface/graph_adt.h>

class GraphImpl : Graph {
private:
    //Adj_matrix, this represents all the possible edges;
    bool** edges;
    const int V_SIZE;
    int E_SIZE;



    int findVerticeIndex(int v);

public:
    GraphImpl(int v);
    ~GraphImpl();

    int V() const override;

    int E() const override;

    bool directed() const override;

    int insert(Edge) override;

    int remove(Edge) override;

    bool edge(int, int) override;

    void verticesEdges(int v,int* array,int foundElements);

    int findEdgesCount(int v);
};