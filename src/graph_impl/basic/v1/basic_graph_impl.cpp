//
// Created by leno on 20.12.23..
//
#include <graph_impl/basic/v1/basic_graph_impl.h>


/**
 * \brief undirected graph
 * \param v number of vertices
 */
GraphImpl::GraphImpl(int v):V_SIZE(v), E_SIZE(0) {
    edges = new bool *[v+1];

    for (int i = 0; i < v+1; ++i) {
        edges[i] = new bool[v];
    }
}

GraphImpl::~GraphImpl() {
    for(int i = 0; i < V_SIZE;++i) {
        delete[] edges[i];
    }
    /**
    *delete // will only invoke the destructor of the first element of the array.

    delete[] // will invoke the destructor for *each* element of the array.

     */
    delete[] edges;
}

/**
 * \brief 
 * \return number of vertices
 */
int GraphImpl::V() const {
    return V_SIZE;
}


/**
 * \brief 
 * \return number of edges
 */
int GraphImpl::E() const {
    return E_SIZE;
}

/**
 * \brief 
 * \return 
 */
bool GraphImpl::directed() const {
    return false;
}


/**
 * \brief
 *  check wheter a graph has cycle. It does not check how many, it just returns when it finds the first one
 * using BFS algorithm (using queueing)
 * \return
 */
bool GraphImpl::cycle() const {
    bool visited[V_SIZE] = {false};
    queue<int> queue;

    queue.push(E_SIZE);

    while(!queue.empty()) {
        int vertice= queue.front();
        queue.pop();
        if(visited[vertice])
            return true;
        else {
            visited[vertice] = true;

            for(int i = 1; i < V_SIZE+1;++i) {
                if(i != vertice) {
                    if(edges[vertice][i]) {
                        if(!visited[i])
                            queue.push(i);
                    }
                }
            }
        }
    }
    return false;
}


int GraphImpl::insert(Edge edge) {
    int v1 = edge.v;
    int v2 = edge.w;

    if(edges[v1][v2]) v1;
    else {
        edges[v1][v2] = true;
        edges[v2][v1] = true;
        E_SIZE++;
        return v1;
    }
}

int GraphImpl::remove(Edge edge) {
    int v1 = edge.v;
    int v2 = edge.w;

    if(!edges[v1][v2]) v1;
    else {
        edges[v1][v2] = false;
        edges[v2][v1] = false;
        E_SIZE--;
        return v1;
    }
}

bool GraphImpl::edge(int i, int i1) {
    return edges[i][i1];
}

/**
 * \brief This function will find all the edges that are going from v. (Basically all nodes connected to vl)
 * \param v
 * \param array
 * \param foundElements
 */
void GraphImpl::verticesEdges(int v, int* array,int foundElements) {
    if(V_SIZE < v)throw -1;
    if(foundElements == 0)return;

    int index = 0;
    for(int i = 0; i < V_SIZE;++i) {
        if(edges[v][i]) {
            if(index >= foundElements)throw -1;

            array[index] = i;
            ++index;
        }
    }
}

int GraphImpl::findEdgesCount(int v) {
    if(V_SIZE < v)throw -1;

    int count = 0;
    for(int i = 0; i < V_SIZE;++i) {
        if(edges[v][i]) {
            count++;
        }
    }
    return count;
}




