
///
// Created by leno on 02.01.24..
//
#include <iostream>
#include <graph_impl/basic/v1/basic_graph_adj_list_repo.h>


/**
 * \brief undirected graph
 * \param v number of vertices
 */
GraphImplAdjList::GraphImplAdjList(int v):V_SIZE(v), E_SIZE(0) {
    edges = new node*[V_SIZE+1];

    for(int i = 0; i < V_SIZE+1;++i) {
        edges[i] = nullptr;
    }

}

GraphImplAdjList::~GraphImplAdjList() {
    for(int i = 1; i < V_SIZE+1;++i ){
        node* parent = edges[i];
        if(parent == nullptr)
            delete parent;
        else {
            while(parent != nullptr) {
                node* tempptr = parent->link;
                std::cout<<"deleting edge "<<i << "   "<< parent->data <<std::endl;
                delete parent;
                parent = tempptr;
            }
        }
    }
    delete[] edges;
}

int GraphImplAdjList::V() const {
    return V_SIZE;
}

int GraphImplAdjList::E() const {
    return E_SIZE;
}

bool GraphImplAdjList::directed() const {
    return false;
}

bool GraphImplAdjList::cycle() const {
}

bool GraphImplAdjList::DFS_print() const {
}

int GraphImplAdjList::insert(Edge e) {
    int v = e.v , w=e.w;


    if(edges[v] == nullptr)
        edges[v] = new node(w,nullptr);
    else
        edges[v] = new node(w,edges[v]);

    if(!directed()) {
        if(edges[w] == nullptr)
            edges[w] = new node(v,nullptr);
        else
            edges[w] = new node(v,edges[w]);
    }
    ++E_SIZE;

}

int GraphImplAdjList::remove(Edge e) {
    int v = e.v , w=e.w;

    node* edge = edges[v];

    node* parent = nullptr;
    if(edge == nullptr) {
        return -1;
    }else {
        while(edge != nullptr) {
            if(edge->data == w) {

                node* lastOne = edge->link;

                if(parent != nullptr) {
                    parent->link = lastOne;
                }else {
                    edges[v] = lastOne;
                }
                edge = nullptr;
                remove(Edge{w,v});
            }else {
                parent = edge;
                edge = edge->link;
            }
        }

    }
}

bool GraphImplAdjList::edge(int v, int w) {
    node* parent = edges[v];

    while(parent != nullptr) {
        if(parent->data == w) {
            return true;
        }
        parent = parent->link;
    }
    return false;
}

void GraphImplAdjList::verticesEdges(int v, int* array, int foundElements) {
}

int GraphImplAdjList::findEdgesCount(int v) {
}

